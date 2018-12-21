#include <stdio.h>

/* print Celcius-Fahrenheit table for cels = -100, -90, ..., 100 */

main()
{
	float celsius, fahr;
	int lower, upper, step;

	lower = -100;
	upper = 100;
	step = 10;

	celsius = lower;
	printf("%7s\t%7s\n", "celsius", "fahr");
	while (celsius <= upper) {
		fahr = (9.0 / 5.0) * celsius + 32.0;
		printf("%7.0f\t%7.2f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
