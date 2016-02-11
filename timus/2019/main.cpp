#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
using namespace std;

bool IsHunter(char ch) {
    return ch < 97;
}

bool IsGhost(char ch) {
    return ch >= 97;
}

bool IsPair(char ch1, char ch2) {
    if (ch1 < ch2)
        return (ch1 + 32) == ch2;
    return (ch1 - 32) == ch2;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector< pair<char, int> > v;
    map<int, int> hunter2ghost;
    int hunterNum = 0;
    int ghostNum = 0;
    for (int pos = 2; pos <= 2*n; ++pos) {
        const char ch = s[pos-1];
        int num = -1;
        if (IsHunter(ch)) {
            num = ++hunterNum;
        } else {
            num = ++ghostNum;
        }

        if (!v.empty() && IsPair(v.back().first, ch)) {
            if (IsHunter(ch)) {
                hunter2ghost[num] = v.back().second;
            } else {
                hunter2ghost[v.back().second] = num;
            }
            v.pop_back();
        } else {
            v.push_back({ch, num});
        }
    }

    if (!v.empty()) {
        cout << "Impossible" << endl;
        return 0;
    }

    for (const auto& h2g : hunter2ghost) {
        cout << h2g.second << ' ';
    }

    return 0;
}
