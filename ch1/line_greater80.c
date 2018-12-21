#include <stdio.h>

#define MAXLINE 1000
#define LOWER	80

int wgetline(char line[], int maxline);

main()
{
	int len;
	char line[MAXLINE];

	while ((len = wgetline(line, MAXLINE)) > 0)
		if (len > LOWER)
			printf("%s", line);
}

int wgetline(char line[], int maxline)
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
