#include <stdio.h>

#define IN	1	/* inside a word */
#define OUT	0	/* outside a word */

/* print input one word per line */
main()
{
	int c, state, newline;

	state = OUT;
	newline = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			state = OUT;
			if (newline) {
				putchar('\n');
				newline = 0;
			}
		}
		else if (state == OUT) {
			putchar(c);
			state = IN;
			newline = 1;
		} else if (state == IN) {
			putchar(c);
		}
	}
}
