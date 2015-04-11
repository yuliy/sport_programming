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

typedef map<int, int> TMap;

static const bool DBG = false;

static void ExtendString(string& s, int X) {
    string tmp = s;
    for (int i = 1; i < X; ++i) {
        s += tmp;
    }
}

static bool CanSplit(const string& s) {
    return false;
}

static string SolveSingleCase() {
    int L, X;
    scanf("%d %d", &L, &X);
    string s;
    cin >> s;
    ExtendString(s, X);
    return CanSplit(s) ? "YES" : "NO";
}

int main() {
    int numberOfTests = 0;
    cin >> numberOfTests;

    for (int i = 1; i <= numberOfTests; ++i) {
        cout << "Case #" << i << ": " << SolveSingleCase() << endl;
    }

    return 0;
}
