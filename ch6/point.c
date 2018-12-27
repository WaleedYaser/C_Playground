#include <stdio.h>

struct point {
	int x;
	int y;
};

struct rect {
	struct point p1;
	struct point p2;
};

/* mkpoint: make a point from x and y components */
struct point mkpoint(int x, int y)
{
	struct point temp;

	temp.x = x;
	temp.y = y;
	return temp;
}

/* addpoint: add two points */
struct point addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r)
{
	return p.x >= r.p1.x && p.x < r.p2.x && p.y >= r.p1.y && p.y < r.p2.y;
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
	struct rect temp;

	temp.p1.x = min(r.p1.x, r.p2.x);
	temp.p1.y = min(r.p1.y, r.p2.y);
	temp.p2.x = max(r.p1.x, r.p2.x);
	temp.p2.y = max(r.p1.y, r.p2.y);

	return temp;
}

int main()
{
	struct point p = mkpoint(5, 7);
	struct point p2 = addpoint(p, mkpoint(8, 2));

	struct rect r = {0, 0, 10, 10};
	printf("%d %d %s\n", p2.x, p2.y, (ptinrect(p, r) ? "in rect" : "out rect"));

	return 0;
}
