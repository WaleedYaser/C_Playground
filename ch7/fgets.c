#include <stdio.h>

/* wfgets: get at most n chars from iop */
char *wfgets(char *s, int n, FILE *iop)
{
	register int c;
	register char *cs;

	cs = s;
	while (--n > 0 && (c = getc(iop)) != EOF)
		if ((*cs++ = c) == '\n')
			break;
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}

/* wfputs: put a string s on file iop */
int wfputs(char *s, FILE *iop)
{
	int c;

	while (c = *s++)
		putc(c, iop);
	return ferror(iop) ? EOF : 0;
}

int main(int argc, char *argv[])
{
	FILE *ifp = fopen(argv[1], "r");
	FILE *ofp = fopen(argv[2], "w");


	char s[200];

	wfgets(s, 100, ifp);
	fclose(ifp);

	wfputs(s, ofp);
	fclose(ofp);
}
