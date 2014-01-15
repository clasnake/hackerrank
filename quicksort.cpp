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

void print(int *a, int start, int end)
{
	for (int i = start; i <= end; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

//Not inplace but doesn't need extra space
int partition_1(int *a, int start, int end)
{
	int p = start;
	for (int i = start + 1; i <= end; i++) {
		if (a[i] < a[start]) {
			swap(a[++p], a[i]);
		}
	}
	swap(a[p], a[start]);
	return p;
}

//Inplace but need extra space O(n)
int partition_2(int *a, int start, int end)
{
	int n = end - start + 1;
	int *temp = new int[n];
	int i = 0, j = n - 1;
	for (int k = start + 1; k <= end; k++) {
		if (a[k] < a[start]) {
			temp[i++] = a[k];
		}
		else {
			temp[j--] = a[k];
		}
	}
	temp[i] = a[start];
	memcpy(a + start, temp, n * sizeof(int));
	reverse(a, start + i + 1, end);
	delete [] temp;
	return start + i;
}

void quicksort(int *a, int start, int end)
{
	if (start < end) {
		int mid = partition_2(a, start, end);
		quicksort(a, start, mid - 1);
		quicksort(a, mid + 1, end);
		print(a, start, end);
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
	quicksort(a, 0, n - 1);
	// print(a, 0, n - 1);
	delete [] a;
	return 0;
}