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

static string Solve(int n, const string &s)
{
    char ch = s[0];
    string res;
    for (int i = 1; i < n; ++i) {
        if (s[i] == ch) {
            res.push_back(ch);
            ++i;
            if (i >= n)
                break;
            ch = s[i];
        }
    }
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        string s;
        cin >> n >> s;
        cout << Solve(n, s) << endl;
    }

    return 0;
}
