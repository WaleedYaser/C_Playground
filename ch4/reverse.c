#include <stdio.h>

int str_len(char s[]);
void reverse(char s[]);
void reverse_r(char s[], int b, int e);

int main()
{
	char s[] = "hello, world!";
	reverse(s);
	printf("%s\n", s);
}

int str_len(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; ++i)
		;
	return i;
}
void reverse(char s[])
{
	reverse_r(s, 0, str_len(s) - 1);
}

void reverse_r(char s[], int b, int e)
{
	if (b >= e)
		return;

	int tmp;
	tmp = s[b];
	s[b] = s[e];
	s[e] = tmp;

	reverse_r(s, b + 1, e - 1);
}
