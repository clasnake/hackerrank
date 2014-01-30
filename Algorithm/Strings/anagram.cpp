#include <iostream>
#include <string>
using namespace std;

int anagram(string s)
{
	int len = s.size();
	if (len & 1) return -1;
	int flag[26] = {0};
	for (int i = len / 2; i < len; i++) {
		flag[s[i] - 'a']++;
	}
	int res = len / 2;
	for (int i = 0; i < len / 2; i++) {
		if (flag[s[i] - 'a']) {
			flag[s[i] - 'a']--;
			res--;
		}
	}
	return res;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		cout << anagram(s) << endl;
	}
	return 0;
}