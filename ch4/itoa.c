#include <stdio.h>

int str_len(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; ++i)
		;
	return i;
}
void itoa(int n, char s[])
{
	if (n < 0) {
		s[0] = '-';
		s[1] = '\0';
		n = -n;
	}
	if (n / 10)
		itoa(n / 10, s);

	int l = str_len(s);
	s[l++] = '0' + n % 10;
	s[l] = '\0';
}

int main()
{
	char s[100];
	itoa(-4653, s);
	s[0] = '\0';
	itoa(938, s);
	s[0] = '\0';
	itoa(773, s);
	printf("%s\n", s);
}
