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

using ui64 = unsigned long long;

ui64 Factorial(ui64 n) {
    ui64 res = 1;
    for (ui64 i = 1; i <= n; ++i) {
        res *= i;
    }
    return res;
}

ui64 Ckn(ui64 k, ui64 n) {
    //cout << "Cnk: " << k << ' ' << n << ' ';
    ui64 m = (n-k);
    if (m < k)
        swap(m, k);

    ui64 res = 1;

    for (ui64 i = m + 1; i <= n; ++i) {
        res *= i;
    }

    for (ui64 i = 1; i <= k; ++i) {
        res /= i;
    }

    //cout << res << endl;
    return res;
}

int main() {
    string s;
    ui64 k;
    cin >> s >> k;

    unordered_map<char, ui64> colour2count;
    for (const char ch : s) {
        ++colour2count[ch];
    }

    map<ui64, string> count2colours;
    for (const auto& elem : colour2count) {
        count2colours[ elem.second ] += elem.first;
    }

    ui64 stonesCount = 0;
    ui64 varsCount = 1;
    auto it = count2colours.rbegin();
    for (;
        it != count2colours.rend() && k > 0;
        ++it
    ) {
        const ui64 count = it->first;
        const string& colours = it->second;
        const size_t p = colours.size();
        if (p <= k) {
            //cout << "(1)" << endl;
            stonesCount += count * p;
            k -= p;
        } else {
            /*
            cout << "(2)" << endl
                << "k=" << k << endl
                << "p=" << p << endl;
            */
            varsCount = Ckn(k, p);
            if (stonesCount == 0) {
                stonesCount = count * k;
            }
            k = 0;
        }
    }

    cout << stonesCount << ' ' << varsCount << endl;

    return 0;
}
