#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "calc.h"

#define MAXOP		100		/* max size of operands or operators */

double vars[26];
double last;

/* reverse polish calculator */
int main()
{
	int type, v;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case MATHLIB:
				if (strcmp(s, "sin") == 0)
					push(sin(pop()));
				else if (strcmp(s, "cos") == 0)
					push(cos(pop()));
				else if (strcmp(s, "tan") == 0)
					push(tan(pop()));
				else if (strcmp(s, "pow") == 0) {
					op2 = pop();
					push(pow(pop(), op2));
				} else if (strcmp(s, "last") == '0') 
					printf("the last recently printed value is %.8g\n", last);
				else
					printf("error: unknown command %s.\n", s);
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
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				push((int) pop() % (int) op2);
				break;
			case VARIABLE:
				v = s[0];
				last = vars[v - 'a'] = pop();
				push(last);
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unkown command %s\n", s);
				break;
		}
	}
}
