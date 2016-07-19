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

    cout << "mods: " << endl;
    for (const auto mod : mods) {
        cout << mod.first << '\t' << mod.second << endl;
    }
    cout << endl;

    vector<int> asc = a;
    vector<int> dsc = a;

    sort(asc.begin(), asc.end());
    sort(dsc.begin(), dsc.end(), greater<int>());

    const auto mz = mods.size();
    for (int i = 0; i < mz; ++i) {
        const int r = mods[i].second;
        const int l = (i < (mz-1)) ? mods[i+1].second : 0;
        cout << l << '\t' << r << endl;
        for (int i = l; i != r; ++i) {
            a[i] = (mods[i].first == 1)
                ? asc[i]
                : dsc[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
