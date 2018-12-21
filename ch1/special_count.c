#include <stdio.h>

/* count blanks, tabs, and newlines */

main()
{
	int c;
	long bc, tc, lc;

	bc = 0; tc = 0; lc = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++bc;
		else if (c == '\t')
			++tc;
		else if (c == '\n')
			++lc;
	}

	printf("blanks: %ld, tabs: %ld, lines: %ld.\n", bc, tc, lc);
}
