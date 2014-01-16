#include <iostream>
#include <cstring>
using namespace std;

int merge(int *a, int start, int mid, int end)
{
	int sum = 0;
	int i = mid, j = end;
	int n = end - start + 1;
	int *temp = new int[n];
	int k = n - 1;
	while (i >= start && j >= mid + 1) {
		if (a[i] > a[j]) {
			sum += (j - mid);
			temp[k--] = a[i--];
		}
		else {
			temp[k--] = a[j--];
		}
	}
	while (i >= start) {
		temp[k--] = a[i--];
	}
	while (j >= mid + 1) {
		temp[k--] = a[j--];
	}
	memcpy(a + start, temp, n * sizeof(int));
	delete [] temp;
	return sum;
}

int count_insertion(int *a, int start, int end)
{
	int sum = 0;
	if (start < end) {
		int mid = start + (end - start) / 2;
		sum += count_insertion(a, start, mid);
		sum += count_insertion(a, mid + 1, end);
		sum += merge(a, start, mid, end);
	}
	return sum;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(int *a, int start, int end, int &ret)
{
	int sum = 0;
	int p = start - 1;
	for (int i = start; i <= end - 1; i++) {
		if (a[i] < a[end]) {
			swap(a[++p], a[i]);
			sum++;
		}
	}
	swap(a[++p], a[end]);
	sum++;
	ret = p;
	return sum;
}

int quicksort(int *a, int start, int end)
{
	int sum = 0;
	if (start < end) {
		int mid;
		sum += partition(a, start, end, mid);
		sum += quicksort(a, start, mid - 1);
		sum += quicksort(a, mid + 1, end);
	}
	return sum;
}

void print(int *a, int start, int end)
{
	for (int i = start; i <= end; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	int *a = new int[n];
	int *b = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	cout << count_insertion(a, 0, n - 1) - quicksort(b, 0, n - 1) << endl;
	delete [] a;
	return 0;
}