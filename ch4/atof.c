#include <ctype.h>
#include <stdio.h>

#define MAXLINE 1000

double atof(char s[]);
double atofe(char s[]);
int wgetline(char s[], int max);

int main()
{
	double sum;
	char line[MAXLINE];

	sum = 0;
	while(wgetline(line, MAXLINE) > 0)
		printf("%g\n", atofe(line));

	return 0;
}

double atof(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); ++i)
		;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		++i;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); ++i) {
		val = 10 * val + (s[i] - '0');
		power *= 10;
	}
	return sign * val / power;
}

double atofe(char s[])
{
	double val, power;
	int i, vsign, e, esign, eval;

	for (i = 0; isspace(s[i]); ++i)
		;

	vsign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		++i;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		++i;

	for (power = 1.0; isdigit(s[i]); ++i) {
		val = 10 * val + (s[i] - '0');
		power *= 10;
	}

	if (s[i] == 'e' || s[i] == 'E')
		++i;
	else
		return vsign * val / power;

	esign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		++i;

	for (e = 0; isdigit(s[i]); ++i)
		e = 10 * e + (s[i] - '0');

	for (eval = 1; e > 0; --e)
		eval *= 10;

	return (esign > 0) ? vsign * val * eval / power : vsign * val / (power * eval);
}

int wgetline(char s[], int max)
{
	int i, c;

	for (i = 0; i < max && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
