#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int unfairness(vector<int> &a, int k)
{
	sort(a.begin(), a.end());
	int unfairness = a[k - 1] - a[0];
	for (int i = 1; i <= a.size() - k; i++) {
		if (a[i + k - 1] - a[i] < unfairness) {
			unfairness = a[i + k - 1] - a[i];
		}
	}
	return unfairness;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	cout << unfairness(a, k) << endl;
	return 0;
}