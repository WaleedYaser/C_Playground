#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c, c2;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	i = 0;
	if (isalpha(c)) {
		while(isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);
		return MATHLIB;			/* math library */
	}

	if (!isdigit(c) && c != '.' && c != '-') {
		if (c == '=') {
			if (isalpha(c2 = getch())) {
				s[0] = c2;
				return VARIABLE;
		} else if (c2 != EOF)
			ungetch(c2);
		}
		return c;				/* not a number */
	}
	if (isdigit(c) || c == '-')	/* collect int part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')				/* collect fractional part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
