#include <stdio.h>

int atoi(char s[]);
int lower(int c);

int main()
{
	char s[] = "265 ";
	int r;
	r = 100 + atoi(s);
	printf("%d\n", r);
	printf("%c\n", lower('Y'));
}

int atoi(char s[]) {
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + s[i] - '0';
	return n;
}

int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}
