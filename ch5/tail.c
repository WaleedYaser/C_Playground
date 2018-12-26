#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULTTAILNUM	10
#define MAXLINES	1000

int readlines(char *lines[], int max);
void writelines(char *lines[], int n);

char *lines[MAXLINES];

int main(int argc, char *argv[])
{
	int nlines;
	int tailnum, p;

	if (argc == 1)
		tailnum = DEFAULTTAILNUM;
	else if (argc == 2 && **++argv == '-') {
		if ((p = atoi(++(*argv))) > 0)
			tailnum = p;
		else {
			printf("error: wrong option\n");
			return 1;
		}
	} else {
		printf("error: wrong number of options\n");
		return 1;
	}

	if ((nlines = readlines(lines, MAXLINES)) >= 0) {
		if (nlines < tailnum)
			tailnum = nlines;
		writelines(lines + nlines - tailnum, tailnum);
		return 0;
	} else {
		printf("error: input too big\n");
			return 1;
	}
}

int get_line(char *s, int max);
char *alloc(int n);

int readlines(char *lines[], int max)
{
	int len, nlines;
	char *p, line[max];

	nlines = 0;
	while ((len = get_line(line, max)) > 0) {
		if (nlines >= max || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0';
			strcpy(p, line);
			lines[nlines++] = p;
		}
	}

	return nlines;
}

void writelines(char *lines[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lines[i]);
}

int get_line(char *s, int max)
{
	int c, i, l;

	for (i =0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

#define ALLOCSIZE	1000

char allocbuf[ALLOCSIZE];
char *allocp = allocbuf;

char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	} else 
		return 0;
}
