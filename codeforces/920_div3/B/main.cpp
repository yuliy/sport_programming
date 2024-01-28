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
#include <utility>
using namespace std;

using ui64 = unsigned long long;
using i64 = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        string s, f;
        cin >> s >> f;

        int z = 0, k = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j] != f[j])
                (s[j] == '1') ? ++k : ++z;
        }

        cout << max(z, k) << endl;
    }

    return 0;
}
