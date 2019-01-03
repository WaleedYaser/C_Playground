#include <fcntl.h>

int get(int fd, long pos, char *buf, int n);

int main(int argc, char *argv[])
{
	char buf[250];
	int fd;

	fd = open(*++argv, O_RDONLY, 0);
	get(fd, 10L, buf, 15);

	close(fd);
	write(1, buf, 15);

	char c = '\n';
	write(1, &c, 1);

	return 0;
}

/* get: read n bytes from position pos */
int get(int fd, long pos, char *buf, int n)
{
	if (lseek(fd, pos, 0) >= 0)		/* get to pos */
		return read(fd, buf, n);
	else
		return -1;
}
