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

    if ((X >= 7) || (area % X))
        return "RICHARD";

    if ((X == 1) || (X == 2))
        return "GABRIEL";

    if (R > C)
        swap(R, C);
    return ((R >= (X-1)) && (C >= X)) ? "GABRIEL" : "RICHARD";
}

int main() {
    int numberOfTests = 0;
    cin >> numberOfTests;

    for (int i = 1; i <= numberOfTests; ++i) {
        cout << "Case #" << i << ": " << SolveSingleCase() << endl;
    }

    return 0;
}
