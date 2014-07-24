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
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    vector<int> res(n);
    res[n-1] = 1;
    set<int> dict;
    dict.insert(a[n-1]);
    for (int i = n - 2; i >= 0; --i) {
        set<int>::const_iterator iter = dict.find(a[i]);
        if (iter != dict.end()) {
            res[i] = res[i+1];
        } else {
            res[i] = res[i+1] + 1;
            dict.insert(a[i]);
        }
    }

    for (int i = 0; i < m; ++i) {
        int li = 0;
        scanf("%d", &li);
        printf("%d\n", res[li-1]);
    }

    return 0;
}
