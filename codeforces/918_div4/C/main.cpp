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

using ui64 = unsigned long long;
using i64 = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    vector<ui64> sq;
    for (ui64 i = 1; (i*i) <= (2ULL*1e14); ++i) {
        sq.push_back(i*i);
    }

    ui64 t;
    cin >> t;
    for (ui64 i = 0; i < t; ++i) {
        ui64 n;
        cin >> n;
        ui64 sum = 0;
        for (ui64 j = 0; j < n; ++j) {
            ui64 tmp;
            cin >> tmp;
            sum += tmp;
        }

        if (binary_search(sq.begin(), sq.end(), sum))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
