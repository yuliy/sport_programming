#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
using namespace std;

int Solve(int n, int k) {
    const int s = n % k;
    const int p = (s == 0)
        ? (n / k)
        : ((n-s) / (k-1));

    cout
        << endl
        << p << ' ' << s
        << endl;

    if (s == 0) {
        return p * p * k * (k - 1) / 2;
    }

    const int a = p * p * (k - 1) * (k - 2) / 2;
    const int b = s * p * (k - 1);

    cout
        << a << ' ' << b
        << endl;

    return a + b;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int n, k;
        cin >> n >> k;
        cout << Solve(n, k) << endl;
    }

    return 0;
}
