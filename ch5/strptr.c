#include <stdio.h>
#include <ctype.h>
#include <string.h>

char * str_n_cpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for ( ; i < n; ++i)
		dest[i] = '\0';

	return dest;
}

char * str_n_cat(char *dest, const char *src, size_t n)
{
	size_t dest_len = strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; ++i)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return dest;
}

int str_n_cmp(const char *s1, const char *s2, size_t n)
{
	size_t i;
	
	for (i = 0; i < n && s1[i] != '\0' && s1[i] == s2[i]; ++i)
		;

	return s1[i] - s2[i];
}

int main()
{
	char *s1 = "hello";
	char *s2 = "hello";
	char *s3 = "world";

	printf("%d\n", str_n_cmp(s1, s2, 3));
	printf("%d\n", str_n_cmp(s1, s3, 3));
	printf("%d\n", str_n_cmp(s3, s1, 3));
}
