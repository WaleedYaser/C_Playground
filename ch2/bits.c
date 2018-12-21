#include <stdio.h>

#define B(x) s_to_binary_(#x)

static inline unsigned long long s_to_binary_(const char *s)
{
	unsigned long long i = 0;
	while (*s) {
		i <<= 1;
		i += *s++ - '0';
	}
	return i;
}

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invertbits(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);
unsigned rightrot(unsigned x, int n);

int main()
{
	unsigned i;
	i = 142;
	printf("%u\n", getbits(i, 2, 3));
	printf("%u\n", setbits(i, 4, 3, 12));
	printf("%u\n", invertbits(i, 4, 3));
	printf("%u\n", rightrot(i, 4));
	printf("%d\n", bitcount(i));
}

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	unsigned mask = ~(~0 << n) << (p + 1 - n);
	y = (y << (p + 1 -n)) & mask;
	return (x & ~mask) | y;
}

unsigned invertbits(unsigned x, int p, int n)
{
	unsigned b = getbits(x, p, n);
	return setbits(x, p, n, ~b);
}

unsigned rightrot(unsigned x, int n)
{
	while (n-- > 0) {
		if (x & 1)
			x = (x >> 1) | ~(~0u >> 1);
		else
			x = x >> 1;
	}
	return x;
}

int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x &= (x-1))
		++b;
	return b;
}
