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
    scanf("%d %d", &n, &m);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    vector<pair<int, int>> mods;
    for (int i = 0; i < m; ++i) {
        pair<int, int> mod;
        scanf("%d %d", &(mod.first), &(mod.second));

        while (mods.size() && (mods.back().second < mod.second)) {
            mods.pop_back();
        }

        if (mods.empty() || (mods.back().first != mod.first)) {
            mods.push_back(mod);
        }
    }

    vector<int> asc = a;
    vector<int> dsc = a;

    sort(asc.begin(), asc.end());
    sort(dsc.begin(), dsc.end(), greater<int>());

    const auto mz = mods.size();
    for (int i = mz - 1; i >= 0; --i) {
        const int r = mods[i].second;
        const int l = (i > 0) ? mods[i-1].second : 0;
            for (int i = l; l != r; ++i) {
                a[i] = (mods[i].first == 1)
                    ? asc[i]
                    : dsc[i];
            }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }

    return 0;
}
