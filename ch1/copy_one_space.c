#include <stdio.h>

/* copy input to output, relace one or more blanks by single blank */

main()
{
	int c, lcb;
	lcb = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' && lcb)
			continue;
		else if (c == ' ')
			lcb = 1;
		else
			lcb = 0;

		putchar(c);
	}
}
