#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100;

int main()
{
	int n;
	cin >> n;
	int *c = new int[maxn];
	memset(c, 0, sizeof(c));
	while (n--) {
		int x;
		cin >> x;
		c[x]++;
	}
	for (int i = 0; i < maxn; i++) {
		cout << c[i] << " ";
	}
	delete [] c;
	return 0;
}