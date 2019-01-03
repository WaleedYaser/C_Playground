#include <fcntl.h>

#define EOF		-1
#define BUFSIZ	1024

int getchar(void);
int bgetchar(void);
void putcahr(char c);

int main()
{
	char c;

	while ((c = bgetchar()) != EOF)
		putchar(c);

	return 0;
}

/* getchar: unbuffered single character input */
int getchar(void)
{
	char c;
	return (read(0, &c, 1) == 1) ? (unsigned char) c : -1;
}

/* putchar: unbuffered single character output */
void putchar(char c)
{
	write(1, &c, 1);
}

/* bgetchar: buffered single character input */
int bgetchar(void)
{
	static char buf[BUFSIZ];
	static char *bufp = buf;
	static int n = 0;

	if (n == 0) {		/* buffer is empty */
		n = read(0, buf, sizeof buf);
		bufp = buf;
	}
	return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
