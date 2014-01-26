#include <iostream>
#include <cstring>
#define MODULO 1000000007
#define MAX 1001
using namespace std;

long long mod_add(long long x, long long y)
{
	return (x + y) % MODULO;
}

long long mod_sub(long long x, long long y)
{
	return (x - y + MODULO) % MODULO;
}

long long mod_mult(long long x, long long y)
{
	return (x * y) % MODULO;
}

long long solve(int n, int  m)
{
	long long single_row[MAX];
	memset(single_row, 0, sizeof(single_row));
	single_row[1] = 1;
	single_row[2] = 2;
	single_row[3] = 4;
	single_row[4] = 8;
	for (int i = 5; i <= m; i++) {
		for (int j = 1; j <= 4; j++) {
			single_row[i] = mod_add(single_row[i], single_row[i - j]);
		}
	}
	long long raw_result[MAX];
	for (int i = 1; i <= m; i++) {
		long long res = 1;
		for (int j = 1; j <= n; j++) {
			res = mod_mult(res, single_row[i]);
		}
		raw_result[i] = res;
	}
	long long result_with_holes[MAX];
	long long final_result[MAX];
	final_result[1] = raw_result[1];
	for (int i = 2; i <= m; i++) {
		final_result[i] = raw_result[i];
		for (int j = 1; j <= i - 1; j++) {
			final_result[i] = mod_sub(final_result[i], mod_mult(final_result[j], raw_result[i - j]));
		}
	}
	return final_result[m];
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		cout << solve(n, m) << endl;
	}
	return 0;
}