#define NAME_MAX	14		/* longest filename component; system dependent */


typedef struct {			/* portable directory entry */
	long ino;					/* inode number */
	char name[NAME_MAX + 1];	/* name + '\0' terminator */
} W_Dirent;

typedef struct {			/* minimal Dir: no buffering, etc. */
	int fd;						/* file descriptor for the directory */
	W_Dirent d;					/* the directory entry */
} W_DIR;

W_DIR *w_opendir(char *dirname);
W_Dirent *w_readdir(W_DIR *dfd);
void w_closedir(W_DIR *dfd);
