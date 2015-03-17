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

struct TFoo {
    int HemDist;
    bool AFlags[26];
    bool BFlags[26];
    bool PairFound;
    pair<int, int> Pair;

    TFoo()
        : HemDist(0)
        , PairFound(false)
    {
        for (int i = 0; i < 26; ++i) {
            AFlags[i] = BFlags[i] = false;
        }
    }
};

TFoo calc_hemming(const string& a, const string& b) {
    TFoo res;
    const size_t sz = a.size();
    map<string, size_t> para2idx;
    for (size_t i = 0; i < sz; ++i) {
        if (a[i] == b[i])
            continue;

        res.HemDist += 1;

        res.AFlags[ a[i] - 'a' ] = true;
        res.BFlags[ b[i] - 'a' ] = true;

        if (res.PairFound)
            continue;

        string p("  ");
        p[0] = a[i];
        p[1] = b[i];

        map<string, size_t>::const_iterator it = para2idx.find(p);
        if (it != para2idx.end()) {
            res.PairFound = true;
            res.Pair = make_pair(it->second, i);
        } else {
            string invp("  ");
            invp[0] = b[i];
            invp[1] = a[i];
            para2idx.insert(make_pair(
                invp, i
            ));
        }
    }
    return res;
}

int find_char_pos(const string& s, char ch) {
    const int sz = s.size();
    for (int i = 0; i < sz; ++i) {
        if (s[i] == ch) {
            return i;
        }
    }

    return -1;
}

int main() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    const TFoo res = calc_hemming(a, b);

    if (res.HemDist <= 1) {
        cout << res.HemDist << endl
            << "-1 -1" << endl;
        return 0;
    }

    if (res.PairFound) {
        cout << (res.HemDist - 2) << endl
            << (res.Pair.first + 1) << " " << (res.Pair.second + 1) << endl;
        return 0;
    }

    bool commonFound = false;
    char common = ' ';
    for (int i = 0; i < 26; ++i) {
        if (res.AFlags[i] && res.BFlags[i]) {
            commonFound = true;
            common = 'a' + i;
        }
    }

    if (commonFound) {
        int idx1 = -1;
        int idx2 = -1;
        const int sz = a.size();
        for (int i = 0; i < sz; ++i) {
            if (a[i] == b[i])
                continue;

            if (a[i] == common)
                idx1 = i;
            if (b[i] == common)
                idx2 = i;
        }

        cout << (res.HemDist - 1) << endl
            << (idx1 + 1) << " " << (idx2 + 1) << endl;
    } else {
        cout << res.HemDist << endl
            << "-1 -1" << endl;
    }

    return 0;
}
