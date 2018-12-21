#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXOP		100		/* max size of operands or operator */
#define NUMBER		'0'		/* signal that a number was found */
#define MATHLIB		'1'		/* signal that a library function was found */
#define VARIABLE	'2'		/* signal that a variable was found */

int getop(char s[]);

void push(double f);
double pop(void);
void print_top();
void duplicate_top();
void swap_top();
void clear();

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

	/* test stack functions */
	printf("=== stack text ===\n");
	for (int i = 0; i < 10; ++i)
		push(i);
	print_top();
	swap_top();
	print_top();
	duplicate_top();
	for (int i = 0; i < 5; ++i)
		printf("%.8g ", pop());
	printf("\n");
	clear();
	pop();
}

#define MAXVAL	100

int sp = 0;				/* next free stack position */
double val[MAXVAL];		/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

void print_top()
{
	if (sp > 0)
		printf("%.8g\n", val[sp - 1]);
	else
		printf("error: stack empty\n");
}

void duplicate_top()
{
	if (sp > 0)
		push(val[sp - 1]);
	else
		printf("error: stack empty\n");
}

void swap_top()
{
	if (sp > 1) {
		double tmp = val[sp - 1];
		val[sp - 1] = val[sp - 2];
		val[sp - 2] = tmp;
	} else
		printf("error: stack too short for swap\n");
}

void clear()
{
	sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);
void ungets(char s[]);

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

#define BUFSIZE 100

char buf[BUFSIZE];			/* buffer for ungetch */
int bufp = 0;				/* next free position in buf */

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

void ungets(char s[])
{
	for (int i = strlen(s) - 1; i >= 0; --i)
		ungetch(s[i]);
}
