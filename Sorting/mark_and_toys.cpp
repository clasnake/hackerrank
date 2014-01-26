#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, money;
	cin >> n >> money;
	int *toys = new int[n];
	for (int i = 0; i < n ; i++) {
		cin >> toys[i];
	}
	sort(toys, toys + n);
	int sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (sum + toys[i] > money) {
			break;
		}
		else {
			sum += toys[i];
			count++;
		}
	}
	cout << count;
	delete [] toys;
	return 0;
}