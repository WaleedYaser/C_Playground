#include <stdio.h>
#include <limits.h>

int strlen(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; ++i)
		;
	return i;
}

void reverse(char s[])
{
	int i, j, c;
	for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[])
{
	int i, sign, r;

	sign = n;
	i = 0;
	do {
		r = n % 10;
		s[i++] = ((sign > 0)? r : -r) + '0';
	} while ((n /= 10) != 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int mod(int n)
{
	return ((n > 0)? n : -n);
}
void itob(int n, char s[], int b)
{
	int i, sign, r;

	sign = n;
	i = 0;
	do {
		r = n % b;
		if (mod(r) > 9) {
			s[i++] = mod(r) - 10 + 'a';
		}
		else
			s[i++] = mod(r) + '0';
	} while ((n /= b) != 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void itoaf(int n, char s[], int m)
{
	int i, sign, r;

	sign = n;
	i = 0;
	do {
		r = n % 10;
		s[i++] = mod(r) + '0';
	} while (n /= 10);

	if (sign < 0)
		s[i++] = '-';

	while (i < m)
		s[i++] = ' ';

	s[i] = '\0';
	reverse(s);
}

int main()
{
	int x;
	x = INT_MIN;
	char s[1000];
	itoa(x, s);
	printf("%d\t%s\n", x, s);
	itob(x, s, 2);
	printf("%d\t%s\n", x, s);
	itob(x, s, 8);
	printf("%d\t%s\n", x, s);
	itob(x, s, 16);
	printf("%d\t%s\n", x, s);
	itoaf(424, s, 16);
	printf("424 %s\n", s);
}
