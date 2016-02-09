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

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    auto it1 = s1.begin();
    auto it2 = s2.begin();
    int res = 0;
    for (; it1 != s1.end() || it2 != s2.end(); ++res) {
        if (it1 == s1.end()) {
            ++it2;
            continue;
        }

        if (it2 == s2.end()) {
            ++it1;
            continue;
        }

        const char c1 = *it1;
        const char c2 = *it2;

        if (c1 == 'L' && c2 == 'L') {
            ++it1;
            ++it2;
            continue;
        }

        if (c1 == 'R' || c1 == 'F') {
            ++it1;
        }

        if (c2 == 'R' || c2 == 'F') {
            ++it2;
        }
    }

    cout << res << endl;
    return 0;
}
