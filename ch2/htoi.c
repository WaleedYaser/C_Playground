#include <stdio.h>

#define TRUE  1
#define FALSE 0

int htoi(char s[]);

int main() 
{
	printf("%d\n",htoi("0xAbcdef9"));
}

int htoi(char s[])
{
	int i, n;

	i = n = 0;

	if (s[0] == '0' && s[1] != '\0' && (s[1] == 'X' || s[1] == 'x'))
		i = 2;

	while (s[i] != '\0') {
		if (s[i] >= '0' && s[i] <= '9')
			n = n * 16 + s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			n = n * 16 + 10 + s[i] - 'a';
		else if (s[i] >= 'A' && s[i] <= 'F')
			n = n * 16 + 10 + s[i] - 'A';
		else
			break;
		++i;
	}
	return n;
}
