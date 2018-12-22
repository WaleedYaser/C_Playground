#include <stdio.h>

void str_cat(char *s, char *t);

int main()
{
	char s[100] = "hello, ";
	char *t = "world!";

	str_cat(s, t);
	printf("%s\n", s);
}

void str_cat(char *s, char *t)
{
	/* move s pointer to the end of s */
	while (*s != '\0')
		s++;

	/* append t to s */
	while (*s++ = *t++)
		;
}

