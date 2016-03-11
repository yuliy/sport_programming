#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if (n == 2) {
        cout << 0 << endl;
        return 0;
    }

    const int res = (k <= n/2)
        ? (n - k - 2)
        : (k - 3);
    cout << res << endl;
    return 0;
}
