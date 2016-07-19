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

    const int maxPrefix = mods[0].second;
    vector<int> tmp(a.begin(), a.begin() + maxPrefix);
    sort(tmp.begin(), tmp.end());

    int left = 0;
    int right = maxPrefix - 1;

    const auto mz = mods.size();
    int curPos = maxPrefix - 1;
    for (int i = 0; i < mz; ++i) {
        const int range = (i < (mz-1))
            ? (mods[i].second - mods[i+1].second)
            : mods[i].second;
        for (int z = 0; z < range; ++z) {
            if (mods[i].first == 1) {
                a[curPos--] = tmp[right--];
            } else {
                a[curPos--] = tmp[left++];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
