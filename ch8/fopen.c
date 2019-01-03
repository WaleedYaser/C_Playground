#include "w_stdio.h"

int main(int argc, char *argv[])
{
	char c1, c2;
	c1 = getchar();
	c2 = getchar();
	putchar(c1);
	putchar(c2);
	_flushbuf(c2, stdout);
	return 0;
}
