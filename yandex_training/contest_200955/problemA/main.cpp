#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(n);
    vector<string> field(n);
    for (int i = 0; i < n; ++i) {
        cin >> field[i];
        for (int j = 0; j < m; ++j) {
            if ('*' == field[i][j]) {
                ++a[j];
                ++b[i];
            }
        }
    }

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ('*' != field[i][j])
                continue;

            if (a[j] <= 1)
                continue;

            if (b[i] <= 1)
                continue;

            const long long cur_res = (a[j] - 1) * (b[i] - 1);
            res += cur_res;
        }
    }

    cout << res << endl;

    return 0;
}
