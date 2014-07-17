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
    string s;
    cin >> s;
    const int n = s.size();

    typedef set<char> TDict;
    TDict dict;
    for (int i = 0; i < n; ++i) {
        dict.insert(s[i]);
    }

    int pos = 0;
    const char min_ch = *dict.begin();
    for (TDict::const_reverse_iterator iter = dict.rbegin(); iter != dict.rend(); ++iter) {
        const char ch = *iter;
        if (ch == min_ch) {
            cout << ch << endl;
            break;
        }

        for (int i = pos; i < n; ++i) {
            if (s[i] == *iter) {
                cout << ch;
                pos = i;
            }
        }

        ++pos;
        if (pos >=n)
            break;
    }

    return 0;
}
