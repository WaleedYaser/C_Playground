#include <ctype.h>
#include <stdio.h>

int getfloat(float *);
int getch(void);
void ungetch(int);

int main()
{
	float x;
	if (getfloat(&x))
		printf("%g\n", x);
}

int getfloat(float *pn)
{
	int power, sign, c, c2;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		if (!isdigit(c2 = getch())) {
			ungetch(c2);
			ungetch(c);
			return 0;
		} else
			c = c2;
	}

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');

	if (c == '.')
		c = getch();
	for (power = 1; isdigit(c); c = getch()) {
		power *= 10;
		*pn = 10 * *pn + (c - '0');
	}

	*pn = *pn * sign / power;
	if (c != EOF)
		ungetch(c);
	return c;
}

#define BUFSIZE 100

static char buf[BUFSIZE];			/* buffer for ungetch */
static int bufp = 0;				/* next free position in buf */

/* getch: get a (possibly pushed back) character */
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
