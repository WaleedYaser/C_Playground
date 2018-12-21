#include <stdio.h>

/* copy input to output */

main()
{
	int c;

	printf("%d\n", EOF);

	while ((c = getchar()) != EOF) {
		putchar(c);
		c = getchar();
	}
}
