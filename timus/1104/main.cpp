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

using i64 = long long;

i64 ToInt(char ch) {
    if (strchr("0123456789", ch))
        return ch - '0';
    return ch - 'A' + 10;
}

int main() {
    string s;
    cin >> s;

    i64 sum = 0;
    i64 maxDigit = ToInt(s[0]);
    for (auto ch : s) {
        const i64 digit = ToInt(ch);
        sum += digit;
        maxDigit= max(maxDigit, digit);
    }

    if (maxDigit == 0) {
        cout << "2" << endl;
        return 0;
    }

    i64 solution = -1;
    for (i64 k = maxDigit + 1; k <= 36; ++k) {
        if (sum % (k-1) == 0) {
            solution = k;
            break;
        }
    }

    if (solution == -1) {
        cout << "No solution." << endl;
    } else {
        cout << solution << endl;
    }

    return 0;
}
