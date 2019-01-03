#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>

void filecopy(int, int);
void error(char *fmt, ...);

int main(int argc, char *argv[])
{
	int fd1, fd2;

	fd2 = 1;
	if (argc == 1) {
		fd1 = 0;
		filecopy(fd1, fd2);
	} else {
		while (--argc > 0)
			if ((fd1 = open(*++argv, O_RDONLY, 0)) == -1)
				error("cat: can't open %s", *argv);
			else {
				filecopy(fd1, fd2);
				close(fd1);
			}
	}
	exit(0);
}

char buf[BUFSIZ];
int n;

void filecopy(int fd1, int fd2)
{
	while ((n = read(fd1, buf, BUFSIZ)) > 0)
		write(fd2, buf, n);
}

void error(char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}
