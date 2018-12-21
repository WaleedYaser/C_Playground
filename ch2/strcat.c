#include <stdio.h>

void strcat(char s[], char t[]);

int main()
{
	char s[1000] = "hello";
	char t[1000] = " ,world!";
	strcat(s, t);
	printf("%s\n", s);
}

void strcat(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0')
		++i;

	while ((s[i++] = t[j++]) != '\0')
		;
}
