#include <stdio.h>

#define MAXLINE 1000

int wgetline(char s[], int max);
int strindex(char s[], char t[]);

char pattern[] = "ould";

int main()
{
	char line[MAXLINE];
	int found = 0;

	while (wgetline(line, MAXLINE) > 0) {
		if (strindex(line, pattern) >= 0) {
			printf("%s\n", line);
			++found;
		}
	}
	return found;
}

int wgetline(char s[], int max)
{
	int i, c;

	for (i = 0; i < max -1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return i;
}

int strindex(char s[], char t[])
{
	int i, j, k, r;

	r = -1;
	for (i = 0; s[i] != '\0'; ++i) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			r = i;
	}
	return r;
}
