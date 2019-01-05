#include <stdio.h>
#include <string.h>
#include <fcntl.h>		/* flags for read and write */
#include <sys/types.h>	/* typedefs */
#include <sys/stat.h>	/* structure returned by state */
#include <stdlib.h>

#include "dirent.h"

void fsize(char *);

/* print file sizes */
int main(int argc, char *argv[])
{
	if (argc == 1)		/* default; current directory */
		fsize(".");
	else
		while (--argc > 0)
			fsize(*++argv);
	return 0;
}

// int stat(char *, struct stat *);
void dirwalk(char *, void (*fcn)(char *));

/* fsize: print size of file "name" */
void fsize(char *name)
{
	struct stat stbuf;

	if (stat(name, &stbuf) == -1) {
		fprintf(stderr, "fsize: can't access %s\n", name);
		return;
	}
	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name, fsize);
	printf("%8ld %s\n", stbuf.st_size, name);
}

#define MAX_PATH	1024

/* dirwalk: apply fcn to all files in dir */
void dirwalk(char *dir, void (*fcn)(char *))
{
	char name[MAX_PATH];
	W_Dirent *dp;
	W_DIR *dfd;

	if ((dfd = w_opendir(dir)) == NULL) {
		fprintf(stderr, "dirwalk: can't open %s\n", dir);
		return;
	}
	while ((dp = w_readdir(dfd)) != NULL) {
		if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0)
			continue;		/* skip self and parent */
		if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
			fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->name);
		else {
			sprintf(name, "%s/%s",dir, dp->name);
			(*fcn)(name);
		}
	}
	w_closedir(dfd);
}

int fstat(int fd, struct stat *);

/* w_opendir: open a directory for w_readdir call */
W_DIR *w_opendir(char *dirname)
{
	int fd;
	struct stat stbuf;
	W_DIR *dp;

	if ((fd = open(dirname, O_RDONLY, 0)) == -1
	 || fstat(fd, &stbuf) == -1
	 || (stbuf.st_mode & S_IFMT) != S_IFDIR
	 || (dp = (W_DIR *) malloc(sizeof(W_DIR))) == NULL)
		return NULL;
	dp->fd = fd;
	return dp;
}

/* w_closedir: close directory opened by w_opendir */
void w_closedir(W_DIR *dp)
{
	if (dp) {
		close(dp->fd);
		free(dp);
	}
}

#include <sys/dir.h>

#define DIRSIZ		256

// struct direct {		/* directory entry */
// 	ino_t d_ino;			/* inode number */
// 	char  d_name[DIRSIZ];	/* long name doesn't have '\0' */
// };

/* w_readdir: read directory entries in sequencd */
W_Dirent *w_readdir(W_DIR *dp)
{
	struct direct dirbuf;	/* local directory structure */
	static W_Dirent d;		/* return: portable staructure */

	while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)) {
		if (dirbuf.d_ino == 0)		/* slot not used */
			continue;
		d.ino = dirbuf.d_ino;
		strncpy(d.name, dirbuf.d_name, DIRSIZ);
		d.name[DIRSIZ] = '\0';		/* ensure termination */
		return &d;
	}
	return NULL;
}
