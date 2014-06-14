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
#include <cctype>
using namespace std;

int main() {
    string s;
    cin >> s;
    int capCount = 0;
    for (auto ch : s) {
        if (isupper(ch))
            ++capCount;
    }

    int left = 0;
    int right = capCount;
    int res = capCount;
    for (auto ch : s) {
        if (isupper(ch)) {
            --right;
        } else {
            ++left;
        }

        res = min(res, right + left);
    }

    cout << res << endl;
    return 0;
}
