#include <stdio.h>


int isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int islower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int isupper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

void expand(char s1[], char s2[])
{
	int i, j, k;

	for (i = 0, j = 0; s1[i] != '\0'; ++i) {
		if (s1[i + 1] == '-' && s1[i + 2] != '\0' &&
			((islower(s1[i]) && s1[i + 2] >= s1[i] && s1[i + 2] <= 'z') ||
			 (isupper(s1[i]) && s1[i + 2] >= s1[i] && s1[i + 2] <= 'Z') ||
			 (isdigit(s1[i]) && s1[i + 2] >= s1[i] && s1[i + 2] <= '9'))) {
				for (k = 0; k <= s1[i + 2] - s1[i]; k++, j++)
					s2[j] = s1[i] + k;
				i += 2;
		} else {
			s2[j++] = s1[i];
		}
	}
	s2[j] = '\0';
}

int main()
{
	char s1[] = "1-5a-f-d a-0-4-";
	char s2[1000];
	expand(s1, s2);
	printf("%s\n", s2);
}
