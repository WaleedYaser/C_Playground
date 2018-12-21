#include <stdio.h>
#include "calc.h"

#define MAXVAL	100

static int sp = 0;				/* next free stack position */
static double val[MAXVAL];		/* value stack */

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

