#include <iostream>
using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;

    long long x = n / a;
    long long y = m / a;
    if (x < n)
        ++x;
    if (y < m)
        ++y;
    cout << x * y << endl;
    return 0;
}
