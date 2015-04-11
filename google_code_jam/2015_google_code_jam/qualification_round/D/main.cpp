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

static const bool DBG = false;


static string SolveSingleCase() {
    int X, R, C;
    scanf("%d %d %d", &X, &R, &C);
    const int area = R * C;

    if (1 == X) {
        return "GABRIEL";
    }

    if (2 == X) {
        return (area % 2) ? "RICHARD" : "GABRIEL";
    }

    if (3 == X) {
        return ((area % 3 == 0) && (R != 1) && (C != 1)) ? "GABRIEL" : "RICHARD";
    }

    if (4 == X) {
        return ((4 == R && 4 == C) || (3 == R && 4 == C) || (4 == R && 3 == C)) ? "GABRIEL" : "RICHARD";
    }

    throw string("ooops!");
}

int main() {
    int numberOfTests = 0;
    cin >> numberOfTests;

    for (int i = 1; i <= numberOfTests; ++i) {
        cout << "Case #" << i << ": " << SolveSingleCase() << endl;
    }

    return 0;
}
