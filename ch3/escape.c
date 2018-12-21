#include <stdio.h>

void escape(char s[], char t[]);
void descape(char s[], char t[]);

int main()
{
	char s[] = "hello,\tworld\n";
	char t[1000];

	escape(s, t);
	descape(t, s);
	printf("%s\n", s);
}

void escape(char s[], char t[])
{
	int i, j;
	
	i = j = 0;
	while (s[i] != '\0') {
		switch (s[i]) {
			case '\t':
				t[j++] = '\\';
				t[j++] = 't';
				break;
			case '\n':
				t[j++] = '\\';
				t[j++] = 'n';
				break;
			default:
				t[j++] = s[i];
				break;
		}
		++i;
	}
	t[j] = '\0';
}

void descape(char s[], char t[])
{
	int i, j;
	
	i = j = 0;
	while (s[i] != '\0') {
		if (s[i] == '\\') {
			switch (s[++i]) {
				case 'n':
					t[j++] = '\n';
					break;
				case 't':
					t[j++] = '\t';
					break;
				default:
					t[j++] = '\\';
					t[j++] = s[i];
			}
		} else {
			t[j++] = s[i];
		}
		++i;
	}
}
