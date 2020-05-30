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
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    v[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (v[i-1] < v[i]) {
            v[i] = v[i-1] + 1;
        }
    }

    cout << (v.back() + 1) << endl;
    return 0;
}
