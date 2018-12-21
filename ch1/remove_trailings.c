#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
int remove_trailing(char line[], int length);

main()
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len > 1) {
			remove_trailing(line, len);
			printf("%s", line);
		}
	}
}

int get_line(char line[], int maxline)
{
	int c, i;

	for (i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

int remove_trailing(char line[], int length)
{
	int i;

	for (i = length-2; i > 0 && (line[i] == ' ' || line[i] == '\t'); --i)
		;
	line[i+1] = '\n';
	line[i+2] = '\0';

	return i+2;
}
