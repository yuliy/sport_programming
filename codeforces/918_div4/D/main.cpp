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

using ui64 = unsigned long long;
using i64 = long long;


bool IsC(char ch) {
    return (ch == 'b') || (ch == 'c') || ('ch == 'd');
}

bool IsV(char ch) {
    return (ch == 'a') || (ch == 'e');
}

void ReverseString(string &s) {
    for (size_t l = 0, r = s.size()-1; l < r; ++l, --r) {
        swap(s[l], s[r]);
    }
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ui64 t;
    cin >> t;
    string s;
    for (ui64 i = 0; i < t; ++i) {
        ui64 n;
        cin >> n;
        cin >> s;
        string res;

        while (!s.empty()) {
            const int len = IsV(s.back()) ? 2 : 3;
            for (int i = 0; i < len; ++i) {
                res.push_back(s.back());
                s.pop_back();
            }

            if (!s.empty())
                res.push_back('.');
        }

        ReverseString(res);
        cout << res << endl;
    }

    return 0;
}
