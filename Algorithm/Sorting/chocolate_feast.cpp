#include <iostream>
using namespace std;

int chocolates(int n, int c, int m)
{
    int sum = n / c;
    int wrapper = sum;
    while(wrapper / m) {
        int added = wrapper / m;
        wrapper = wrapper % m + added;
        sum += added;
    }
    return sum;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n, c, m;
        cin >> n >> c >> m;
        cout << chocolates(n, c, m) << endl;
    }
    return 0;
}
