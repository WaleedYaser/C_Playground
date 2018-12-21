#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 4

int get_line_detabed(char line[], int maxline, int tabstop);

int main()
{
	char line[MAXLINE];

	while (get_line_detabed(line, MAXLINE, TABSTOP) > 0) {
		printf("%s", line);
	}
}

int get_line_detabed(char line[], int maxline, int tabstop)
{
	int i, j, c;

	i = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		if (c == '\t') {
			if ( i > maxline - tabstop -1)
				break;
			for (j = 0; j < tabstop; ++j)
				line[i + j] = ' ';
			i += tabstop;
		}
		else {
			if (i > maxline -1)
				break;
			line[i] = c;
			++i;
		}
	}

	if (c == '\n') {
		line[i] = '\n';
		++i;
	}
	line[i] = '\0';

	return i;
}
