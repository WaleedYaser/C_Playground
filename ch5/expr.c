#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include "../ch4/calc/calc.h"

int gettype(const char *s);

int main(int argc, char *argv[])
{
	int type, v;
	double op2;

	for (int i = 0; i < argc; ++i)
	{
		type = gettype(argv[i]);
		switch (type) {
			case NUMBER:
				push(atof(argv[i]));
				break;
			case MATHLIB:
				if (strcmp(argv[i], "sin") == 0)
					push(sin(pop()));
				else if (strcmp(argv[i], "cos") == 0)
					push(cos(pop()));
				else if (strcmp(argv[i], "tan") == 0)
					push(tan(pop()));
				else if (strcmp(argv[i], "pow") == 0) {
					op2 = pop();
					push(pow(pop(), op2));
				} else {
					printf("error: unknown command %s\n", argv[i]);
					return 1;
				}
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else {
					printf("error: zero divisor\n");
					return 1;
				}
				break;
			case '%':
				op2 = pop();
				push((int) pop() % (int) op2);
				break;
			default:
				printf("error: unknown command %s\n", argv[i]);
				return 1;
				break;
		}
	}
	printf("\t%.8g\n", pop());
}

int gettype(const char *s)
{
	int i;
	
	i = 0;
	if (isalpha(s[0])) {
		while (isalpha(s[++i]))
			;
		return MATHLIB;
	}

	if (!isdigit(s[0]) && s[0] != '.' && s[0] != '-')
		return s[0];

	if (isdigit(s[0]) || s[0] == '-')
		while (isdigit(s[++i]))
			;
	if (s[i] == '.')
		while (isdigit(s[++i]))
			;
	return NUMBER;
}
