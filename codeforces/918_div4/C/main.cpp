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

    vector<int> sq;
    for (int i = 1; i*i <= 1e5; ++i) {
        sq.push_back(i*i);
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;
            sum += tmp;
        }

        if (find(sq.begin(), sq.end(), sum) == sq.end())
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}
