#include <stdio.h>

#define max(A, B) ((A) > (B)? (A) : (B))
#define sqr(A) (A) * (A)
#define dprint(expr) printf(#expr " = %d\n", expr)
#define paste(front, back) front ## back
#define swap(t, x, y) { t tmp; tmp = x; x = y; y = tmp; }
int main()
{
	int a = 9, b = 3;
	int x = max(++a, ++b);
	int s1 = sqr(10);
	int s2 = sqr(b);
	int s3 = sqr(b + 4);
	int paste(name, 1) = 60;
	swap(int, a, b);
	dprint(name1);
}
