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
    size_t LastDiffPairIdx;

    TFoo()
        : HemDist(0)
        , PairFound(false)
        , LastDiffPairIdx( static_cast<size_t>(-1) )
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

        res.LastDiffPairIdx = i;

        res.HemDist += 1;

        res.AFlags[ a[i] - 'a' ] = true;
        res.BFlags[ b[i] - 'a' ] = true;

        string p("  ");
        p[0] = a[i];
        p[1] = b[i];

        map<string, size_t>::const_iterator it = para2idx.find(p);
        if (it != para2idx.end()) {
            res.PairFound = true;
            res.Pair = make_pair(it->second, i);
        } else {
            string invp("  ");
            p[0] = b[i];
            p[1] = a[i];
            para2idx.insert(make_pair(
                invp, i
            ));
        }
    }
    return res;
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
            << res.Pair.first << " " << res.Pair.second << endl;
        return 0;
    }

    for (int i = 0; i < 26; ++i) {
        if (res.AFlags[i] && res.BFlags[i]) {
            cout << (res.HemDist - 1) << endl
                << i << " " << res.LastDiffPairIdx << endl;
        }
    }

    return 0;
}
