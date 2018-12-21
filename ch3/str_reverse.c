#include <stdio.h>

void reverse(char s[]);
int strlen(char s[]);

void main()
{
	char s[] = "hello, world";
	reverse(s);
	printf("%s\n", s);
}

void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int strlen(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; ++i)
		;
	return i;
}
