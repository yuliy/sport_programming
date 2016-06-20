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

using i64 = long long;

const i64 MAX_A = 820;
const i64 MAX_B = 8200;

bool Solve(i64 N) {
    for (i64 a = 0; a <= MAX_A; ++a) {
        for (i64 b = 0; b <= MAX_B; ++b) {
            const i64 d = N - (a * 1234567 + b * 123456);
            if (d < 0) {
                continue;;
            }
            if (d % 1234 == 0) {
                return true;
            }
        }
    }
    return false;
}

bool Solve2(i64 N) {
    for (i64 a = 0; a <= 100; ++a) {
        for (i64 b = 0; b <= 1000; ++b) {
            const i64 d = N - (a * 1234567 + b * 123456);
            if (d < 0) {
                continue;;
            }
            if (d % 1234 == 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    /*
    i64 N;
    cin >> N;
    cout << (Solve(N) ? "YES" : "NO") << endl;
    */

    for (int i = 1e9; i >= 0; --i) {
        cout << i << endl;
        if (Solve(i) != Solve2(i)) {
            cout << "Found! " << i << endl;
            break;
        }
    }
    return 0;
}
