#include <stdio.h>

int str_end(char *s, char *t);

int main()
{
	char *s = "Hello, World!";
	char *t = "World!";
	char *r = "hello";

	printf("%s\n", (str_end(s, t)) ? "found" :  "not found");
	printf("%s\n", (str_end(s, r)) ? "found" :  "not found");
}

int str_end(char *s, char *t)
{
	char *sb = s, *tb = t;

	while (*s != '\0')
		s++;
	while (*t != '\0')
		t++;

	if ((s - sb) < (t - tb))
		return 0;

	while (*t-- == *s--)
		;

	if (t < tb)
		return 1;
	else
		return 0;
}
