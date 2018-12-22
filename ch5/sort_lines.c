#include <stdio.h>
#include <string.h>
#include "alloc.h"

#define MAXLINE		5000			/* max lines to be sorted */
#define MAXLEN		1000			/* max length of any input line */

char *lineptr[MAXLINE];				/* pointers to text lines */
char *blineptr[MAXLINE];

int areadlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int readlines(char **lineptr, int maxlines, int maxlen);

void qsort(char **lineptr, int left, int right);

/* sort input lines */
int main()
{
	int nlines;

	if ((nlines = areadlines(lineptr, MAXLINE)) >= 0) {
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}

	char s[MAXLINE][MAXLEN];

	for (int i = 0; i < MAXLINE; ++i)
		*(blineptr + i) = s[i];

	if ((nlines = readlines(blineptr, MAXLINE, MAXLEN)) >= 0) {
		qsort(blineptr, 0, nlines - 1);
		writelines(blineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

int get_line(char *, int);
char *alloc(int);

/* areadlines: read input lines */
int areadlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = get_line(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0';	/* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

/* readlines: read input lines into predefined array */
int readlines(char **lineptr, int maxlines, int maxlen)
{
	int len, nlines;

	while ((len = get_line(lineptr[nlines], maxlen)) > 0) {
		if (nlines >= maxlines)
			return -1;
		else 
			lineptr[nlines++][len - 1] = '\0';
	}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

/* get_line: read line from istream */
int get_line(char *line, int maxlen)
{
	int i, c;

	for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	if (c == '\n')
		line[i++] = c;

	line[i] = '\0';
	
	return i;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left > right)			/* do nothing if array contains fewer than 2 elements */
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
