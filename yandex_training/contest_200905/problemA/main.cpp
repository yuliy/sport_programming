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

const int MAX_N = 100;
const int MAX_M = 100;

bool flags[26];

static void ClearFlags() {
    for (int i = 0; i < 26; ++i)
        flags[i] = false;
}

static int CalcFlagsCount() {
    int res = 0;
    for (int i = 0; i < 26; ++i) {
        if (flags[i])
            ++res;
    }
    return res;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<string> arr;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        arr.push_back(s);
    }

    long long res = 1;
    for (int j = 0; j < m; ++j) {
        ClearFlags();
        for (int i = 0; i < n; ++i) {
            const char ch = arr[i][j];
            flags[ch - 'A'] = true;
        }
        res *= CalcFlagsCount();
        res %= 1000000007LL;
    }

    cout << res << endl;

    return 0;
}
