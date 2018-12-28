#include <stdio.h>

#define NSYM 10

enum UTYPE
{
	INT,
	FLOAT,
	STR
};

struct {
	char *name;
	int  flags;
	int  utype;
	union {
		int   ival;
		float fval;
		char  *sval;
	} u;
} symtab[NSYM];

union u_tag {
	int		ival;
	float	fval;
	char	*sval;
} u;

int main()
{
	printf("size of int: %u\n", sizeof(int));
	printf("size of float: %u\n", sizeof(float));
	printf("size of pointer: %u\n", sizeof(union utag *));
	printf("size of u_tag: %u\n", sizeof(union u_tag));

	symtab[0].utype = FLOAT;
	symtab[0].u.fval = 0.9f;

	symtab[0].utype = INT;
	symtab[0].u.ival = 10;

	if (symtab[0].utype == INT)
		printf("value of u: %d\n", symtab[0].u.ival);
	else if (symtab[0].utype == FLOAT)
		printf("value of u: %f\n", symtab[0].u.fval);
	else if (symtab[0].utype == STR)
		printf("value of u: %s\n", symtab[0].u.sval);
	else
		printf("bad type %d in utype\n", symtab[0].utype);
}
