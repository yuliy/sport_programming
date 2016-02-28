#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

using ui64 = unsigned long long;

ui64 CalcMinDiff(const set<ui64>& dic) {
    auto it1 = dic.begin();
    auto it2 = ++(dic.begin());
    ui64 res = *it2 - *it1;
    for (; it2 != dic.end(); ++it1, ++it2) {
        res = min(res, *it2 - *it1);
    }
    return res;
}

int main() {
    ui64 a, b, c;
    cin >> a >> b >> c;

    set<ui64> dic;
    dic.insert(a);
    dic.insert(b);
    dic.insert(c);

    if (dic.size() < 3) {
        cout << 1 << endl;
        return 0;
    }

    int res = 1;
    for (;;) {
        ++res;
        const ui64 minDiff = CalcMinDiff(dic);
        if (dic.find(minDiff) != dic.end()) {
            break;
        } else {
            dic.insert(minDiff);
        }
    }

    cout << res << endl;
    return 0;
}
