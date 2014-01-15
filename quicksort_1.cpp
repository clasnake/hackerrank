#include <iostream>
#include <cstring>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void reverse(int *a, int start, int end)
{
	for (int i = 0; i < (end - start + 1) / 2; i++) {
		swap(a[start + i], a[end - i]);
	}
}

void partition(int *a, int n)
{
	int *temp = new int[n];
	int i = 0, j = n - 1;
	for (int k = 1; k < n; k++) {
		if (a[k] < a[0]) {
			temp[i++] = a[k];
		}
		else {
			temp[j--] = a[k];
		}
	}
	temp[i] = a[0];
	memcpy(a, temp, n * sizeof(int));
	reverse(a, i + 1, n - 1);
}

void print(int *a, int n)
{
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	partition(a, n);
	print(a, n);
	return 0;
}