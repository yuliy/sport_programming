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

using i64 = long long;

int main() {
    i64 X, Y, C;
    cin >> X >> Y >> C;

    if ((X + Y) < C) {
        cout << "Impossible" << endl;
    } else {
        const i64 A = min(X, C);
        cout << A << ' ' << (C - A) << endl;
    }

    return 0;
}
