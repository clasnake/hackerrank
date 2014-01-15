#include <iostream>
using namespace std;

long merge(long *a, long start, long mid, long end)
{
	long sum = 0;
	long *temp = new long[end - start + 1];
	long i = mid, j = end;
	long k = end - start;
	while (i >= start && j >= mid + 1) {
		if (a[i] > a[j]) {
			temp[k--] = a[i--];
			sum += j - mid;
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
	k = 0;
	for (long i = start; i <= end; i++) {
		a[i] = temp[k++];
	}
	return sum;
}

long count(long *a, long start, long end)
{
	long sum = 0;
	if (start < end) {
		long mid = start + (end - start) / 2;
		sum += count(a, start, mid);
		sum += count(a, mid + 1, end);
		sum += merge(a, start, mid, end);
	}
	return sum;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		long n;
		cin >> n;
		long *a = new long[n];
		for (long i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << count(a, 0, n - 1) << endl;
		delete [] a;
	}
	return 0;
}