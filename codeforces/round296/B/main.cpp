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

    TFoo()
        : HemDist(0)
    {
        for (int i = 0; i < 26; ++i) {
            AFlags[i] = BFlags[i] = false;
        }
    }
};

TFoo calc_hemming(const string& a, const string& b) {
    TFoo res;
    const size_t sz = a.size();
    for (int i = 0; i < sz; ++i) {
        if (a[i] != b[i]) {
            res.HemDist += 1;
        }

        res.AFlags[ a[i] - 'a' ] = true;
        res.BFlags[ b[i] - 'a' ] = true;
    }
    return res;
}

bool check_has_common_letter(const string& a, const string& b) {

}

int main() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    const TFoo res = calc_hemming(a, b);

    if (res.HemDist <= 1) {
        cout << res.HemDist << endl
            << "-1 -1" << endl;
    }

    return 0;
}
