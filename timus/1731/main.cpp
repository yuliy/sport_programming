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
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cout << i << ' ';
    }
    cout << endl;

    for (int i = 1; i <= m; ++i) {
        cout << (i * n + 1) << ' ';
    }
    cout << endl;

    return 0;
}
