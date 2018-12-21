#include <stdio.h>
#include "alloc.h"

int main()
{
	char *s = alloc(14);
	afree(s);
}
