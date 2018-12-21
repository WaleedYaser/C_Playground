#include <stdio.h>

int str_len(char *);

int main()
{
	char *s = "Hello, World!";
	printf("%d\n", str_len(s));
}

int str_len(char *s)
{
	int i;
	for (i = 0; *s != '\0'; ++s, ++i)
		;
	return i;
}
