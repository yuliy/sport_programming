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
#include <cmath>
using namespace std;

using ui64 = unsigned long long;
using i65 = long long;

static const ui64 MOD = 1e9 + 7;

ui64 Convert(char ch) {
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 10;
    if (ch >= 'a' && ch <= 'z')
        return ch - 'a' + 36;
    if (ch == '-')
        return 62;
    if (ch == '_')
        return 63;
    throw std::logic_error("Invalid input symbol in Convert!");
}

ui64 CalcZeroBitCount(ui64 ch) {
    ui64 res = 0;
    for (ui64 i = 0; i <= 5; ++i) {
        if ((ch & (1 << i)) == 0) {
            ++res;
        }
    }
    return res;
}

int main() {
    string s;
    cin >> s;

    ui64 res = 1;
    for (const auto ch : s) {
        const ui64 code = Convert(ch);
        const ui64 zeroCount = CalcZeroBitCount(code);
        res *= pow(3, zeroCount);
        res %= MOD;
    }

    cout << res << endl;
    return 0;
}
