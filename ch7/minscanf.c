#include <stdio.h>
#include <stdarg.h>

void minscanf(char *fmt, ...);

int main()
{
	int i;
	double d;
	char s[20];

	minscanf("%d %f %s", &i, &d, s);

	printf("%d_%f_%s\n", i, d, s);
	return 0;
}

/* minscanf: minimal scanf with variable argument list */
void minscanf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int *ival;
	double *dval;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			if (getchar() == *p)
				continue;
			else
				return;
		}
		switch(*++p) {
			case 'd':
				ival = va_arg(ap, int *);
				scanf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, double *);
				scanf("%lf", dval);
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++)
					*sval = getchar();
				break;
			default:
				return;
		}
	}
	va_end(ap);
}
