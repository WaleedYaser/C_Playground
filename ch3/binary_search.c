#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
	int v[] = {0, 1, 2, 3, 4, 5, 6, 7};

	printf("%d\n", binsearch(3, v, 8));
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
