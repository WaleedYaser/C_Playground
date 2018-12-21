#include <stdio.h>

void shell_sort(int v[], int n);

int main() 
{
	int v[9] = {2, 555, 11, 6, 22, 67, 1, 9, 5};
	shell_sort(v, 9);
	for (int i = 0; i < 9; ++i)
		printf("%d ", v[i]);
	printf("\n");
}

void shell_sort(int v[], int n)
{
	int gab, i, j, temp;

	for (gab = n / n; gab > 0; gab /= 2)
		for (i = gab; i < n; ++i)
			for (j = i - gab; j >= 0 && v[j] > v[j + gab]; j -= gab) {
				temp = v[j];
				v[j] = v[j + gab];
				v[j + gab] = temp;
			}
}
