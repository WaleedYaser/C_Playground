#include <stdio.h>

void print_str(char s[]);

int main()
{
	char s[] = "hello world!";
	print_str(s);
	return 0;
}

void print_str(char s[])
{
	for (int i = 0; i < 50; ++i) {
		s[i] = 'a';
		printf("%c\n", s[i]);
	}
}
