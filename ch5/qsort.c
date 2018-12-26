#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "lines.h"

#define MAXLINES	5000			/* max lines to be sorted */

char *lineptr[MAXLINES];			/* pointer to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void q_sort(void *lineptr[], int left, int right,
		int (*comp)(void *, void *), int reverse);
int numcmp(char *, char *);
int fstrcmp(const char *s1, const char *s2);

/* sort input lines */
int main(int argc, char *argv[])
{
	int nlines;						/* number of input lines read */
	int numeric = 0;				/* 1 if numeric sort */
	int reverse = 1;				/* -1 if reverse sort */
	int fold = 0;					/* 1 if fold sort */

	int c;
	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
				case 'n': case 'N':
					numeric = 1;
					break;
				case 'r': case 'R':
					reverse = -1;
					break;
				case 'f': case 'F':
					fold = 1;
					break;
				default:
					printf("find illegal option %c\n", c);
					return 1;
					break;
			}

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		q_sort((void **) lineptr, 0, nlines - 1,
				(int (*)(void *, void *))(numeric ? numcmp : (fold ? fstrcmp : strcmp)), reverse);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

/* fstrcmp: compare s1 & s2 ignoring case distiction */
int fstrcmp(const char *s1, const char *s2)
{
	while (*s1 && (tolower(*s1) == tolower(*s2)))
		s1++, s2++;
	return tolower(*(const unsigned char *)s1) - tolower(*(const unsigned char *)s2);
}

/* q_sort: sort v[left]...v[right] int increasing order */
void q_sort(void *v[], int left, int right,
		int (*comp)(void *, void *), int reverse)
{
	int i, last;
	void swap(void **, int, int);

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if((*comp)(v[i], v[left]) * reverse < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	q_sort(v, left, last - 1, comp, reverse);
	q_sort(v, last + 1, right, comp, reverse);
}

#include <stdlib.h>

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void swap(void **v, int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
