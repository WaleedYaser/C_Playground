#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse_line(char line[], int length);

main()
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len > 1)
			reverse_line(line, len);
		printf("%s", line);
	}
}

int get_line(char line[], int maxline)
{
	int i, c;

	for (i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';

	return i;
}

void reverse_line(char line[], int length)
{
	char c;
	int i, l;
	l = length/2 - 1;

	for (int i = 0; i < l; ++i) {
		c = line[i];
		line[i] = line[length-i-2];
		line[length-i-2] = c;
	}
}
