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

struct {
	unsigned int is_keyword : 1;
	unsigned int is_extern  : 1;
	unsigned int is_static  : 1;
} flags; /*field called flags */

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

	printf("size of flags: %u\n", sizeof flags);
	flags.is_extern = flags.is_static = 1;
	if (flags.is_extern && flags.is_static)
		printf("is extern and static\n");
}
