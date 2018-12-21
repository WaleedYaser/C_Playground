#include <stdio.h>

int strlen(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; ++i)
		;
	return i;
}

int trim(char s[])
{
	int n;

	for (n = strlen(s)-1; n >= 0; n --) {
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
	}
	s[n+1] = '\0';
	return n;
}

int main()
{
	char s[] = "hello, world\t \n";
	trim(s);
	printf("%s\n", s);
}
