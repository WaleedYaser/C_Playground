#include <stdio.h>
#include <string.h>

#include "alloc.h"

static int get_line(char *s, int max);

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
