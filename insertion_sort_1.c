#include <stdio.h>
#include <stdlib.h>

void print(int *a, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void insertion(int *a, int n)
{
	int i, j;
	for (i = 1; i < n; i++) {
		int temp = a[i];
		for (j = i; j > 0; j--) {
			if (temp < a[j - 1]) {
				a[j] = a[j - 1];
			}
			else {
				break;
			}
			print(a, n);
		}
		a[j] = temp;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int *a = (int*)malloc(n * sizeof(int));
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	insertion(a, n);
	print(a, n);
	return 0;
}