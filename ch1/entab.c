#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 4

int get_line_entabed(char line[], int maxline, int tabstop);

int main()
{
	char line[MAXLINE];

	while (get_line_entabed(line, MAXLINE, TABSTOP)) {
		printf("%s", line);
	}
}

int get_line_entabed(char line[], int maxline, int tabstop)
{
	int i, j, c;
	char tmp[TABSTOP];

	i = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		if (c == ' ') {
			tmp[0] = c;
			for (j = 1; j < tabstop; ++j) {
				if ((c = getchar()) != ' ') {
					tmp[j] = c;
					break;
				}
			}
			if (j == tabstop) {
				line[i] = '\t';
				++i;
			}
			else {
				for (int k = 0; k <= j; ++k)
					line[i+k] = tmp[k];
				i = i + j + 1;
			}
		}
		else {
			line[i] = c;
			i++;
		}
	}

	if (c == '\n') {
		line[i] = '\n';
		++i;
	}
	line[i] = '\0';

	return i;
}
