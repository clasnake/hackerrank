#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		int *a = new int[n];
		int *b = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		sort(a, a + n);
		sort(b, b + n, cmp);
		bool flag = true;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] + b[i] < k) {
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		delete [] a;
		delete [] b;
	}
	return 0;
}