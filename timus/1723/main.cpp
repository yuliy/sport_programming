#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    const size_t sz = s.length();
    unordered_map<char, int> ch2cnt;
    for (size_t i = 0; i < sz; ++i) {
        ++ch2cnt[s[i]];
    }

    char res = s[0];
    int maxCnt = -1;

    for (const auto& elem : ch2cnt) {
        if (elem.second > maxCnt) {
            res = elem .first;
            maxCnt = elem.second;
        }
    }

    cout << res << endl;
    return 0;
}
