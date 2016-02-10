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

bool Check(const string& s) {
    const size_t sz = s.size();
    for (size_t i = 0, j = sz-1; i < j; ++i, --j) {
        const char ch1 = s[i];
        const char ch2 = s[j];

        if (IsGhost(ch1) && IsHunter(ch2) && ((ch1 - 32) == ch2))
            continue;

        if (IsHunter(ch1) && IsGhost(ch2) && ((ch1 + 32) == ch2))
            continue;

        return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (!Check(s)) {
        cout << "Impossible" << endl;
        return 0;
    }

    const size_t sz = s.size();
    vector<size_t> ghostNumberByPos(sz + 1);
    for (size_t i = 1, num = 1; i <= sz; ++i) {
        if (IsGhost(s[i-1])) {
            ghostNumberByPos[i] = num;
            //cout << s[i-1] << '\t' << i << '\t' << num << endl;
            ++num;
        }
    }

    for (size_t i = 1; i <= sz; ++i) {
        if (IsHunter(s[i-1])) {
            const size_t pos = (i <= (sz/2))
                ? (sz - i + 1)
                : (sz - i + 1);
            cout << ghostNumberByPos[pos] << ' ';
            //cout << s[i-1] << '\t' << pos << '\t' << ghostNumberByPos[pos] << endl;
        }
    }
    cout << endl;

    return 0;
}
