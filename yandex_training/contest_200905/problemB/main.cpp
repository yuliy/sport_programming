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

long long Pow2(long long p) {
    long long res = 1;
    for (int i = 0; i < p; ++i) {
        res <<= 1;
        res %= 1000000007;
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    const int n = s.size();

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        if (s[n-i-1] == '0')
            continue;

        const long long tmp1 = Pow2(i);
        const long long tmp2 = Pow2(n-i-1);
        //cout << i << '\t' << tmp1 << '\t' << tmp2 << endl;

        long long tmp = tmp1 * tmp2;
        tmp %= 1000000007;
        tmp *= tmp1;
        tmp %= 1000000007;

        res += tmp;
        res %= 1000000007;
    }

    cout << res << endl;

    return 0;
}
