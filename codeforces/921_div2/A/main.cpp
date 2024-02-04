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

    const string alpha = "abcdefghijklmnopqrstuvwxyz";

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;

        for (int j = 0; j < n; ++j)
            for (int p = 0; p < k; ++p)
                cout << alpha[p];

        cout << endl;
    }

    return 0;
}
