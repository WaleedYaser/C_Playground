#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
	char line[] = "hello world\n";
	squeeze(line, "wld");
	printf("%s\n", line);
}

void squeeze(char s1[], char s2[])
{
	int i, j, k, b;

	for (i = k = 0; s1[i] != '\0'; ++i) {
		b = 1;
		for (j = 0; s2[j] != '\0'; ++j) {
			if (s1[i] == s2[j]) {
				b = 0;
				break;
			}
		}
		if (b)
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
}
