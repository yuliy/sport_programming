#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

static void PrintDic(const set<long long> &dic) {
    for (set<long long>::const_iterator iter = dic.begin(), end = dic.end(); iter != end; ++iter) {
        cout << *iter << "\t";
    }
    cout << endl;
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    set<long long> dic;
    dic.insert(a);
    dic.insert(b);
    dic.insert(c);

    long long minDiff = abs(a - b);
    if (abs(a - c) < minDiff)
        minDiff = abs(a - c);
    if (abs(b - c) < minDiff)
        minDiff = abs(b - c);

    int res = 0;
    for (;;) {
        ++res;

        //cout << "-" << endl;
        //PrintDic(dic);
        //cout << minDiff << endl << res << endl << endl;

        long long tmp = minDiff;
        for (set<long long>::const_iterator iter = dic.begin(), end = dic.end(); iter != end; ++iter) {
            const long long d = abs(minDiff - *iter);
            if (d < tmp)
                tmp = d;
        }
        dic.insert(minDiff);
        minDiff = tmp;

        if (dic.find(minDiff) != dic.end()) {
            ++res;
            break;
        }
    }

    printf("%d\n", res);

    return 0;
}
