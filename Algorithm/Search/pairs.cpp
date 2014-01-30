#include <iostream>
#include <set>
using namespace std;


int main() {
    int n, k;
    int tmp;
    cin >> n >> k;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        s.insert(tmp);
    }
    int count = 0;
    for (set<int>::iterator i = s.begin(); i != s.end(); i++) {
        tmp = *i;
        if (s.count(tmp + k)) {
            count++;
        }
    }
    cout << count;
    return 0;
}
