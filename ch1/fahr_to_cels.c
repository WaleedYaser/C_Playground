#include <stdio.h>

#define LOWER	0
#define UPPER	300
#define STEP	20

/* printf Fahrenheit-Celcius table for fahr = 0, 20, ..., 300 */

main()
{
	printf("fahr\tcelsius\n");
	for (int fahr = UPPER; fahr >= LOWER; fahr -= STEP)
		printf("%3d\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
}
