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

static long double SolveSingleCase(long double C, long double F, long double X) {
    const long double v0 = 2;
    long double vsum = 0;
    long double prev_res = X / v0;
    for (int i = 0; ; ++i) {
        vsum += (C / (v0 + i*F));
        const long double next_res = vsum + X / (v0 + (i+1) * F);
        if (next_res > prev_res) {
            return prev_res;
        }

        prev_res = next_res;
    }
}

int main() {
    int numberOfTests = 0;
    cin >> numberOfTests;

    for (int i = 1; i <= numberOfTests; ++i) {
        long double C, F, X;
        cin >> C >> F >> X;
        cout << "Case #" << i << ": " << SolveSingleCase(C, F, X) << endl;
    }

    return 0;
}
