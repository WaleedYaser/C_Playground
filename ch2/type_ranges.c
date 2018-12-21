#include <stdio.h>
#include <limits.h>

int main()
{
	printf("char\t[%d\t%d]\n", CHAR_MIN, CHAR_MAX);
	printf("uchar\t[%u\t%u]\n", 0, UCHAR_MAX);
	printf("schar\t[%d\t%d]\n", SCHAR_MIN, SCHAR_MAX);

	printf("short\t[%hd\t%hd]\n", SHRT_MIN, SHRT_MAX);
	printf("ushort\t[%hu\t%hu]\n", 0, USHRT_MAX);

	printf("int\t[%d\t%d]\n", INT_MIN, INT_MAX);
	printf("uint\t[%u\t%u]\n", 0, UINT_MAX);

	printf("long\t[%ld\t%ld]\n", LONG_MIN, LONG_MAX);
	printf("ulong\t[%lu\t%lu]\n", 0, ULONG_MAX);
}
