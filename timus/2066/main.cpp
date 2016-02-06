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

int solveSigns(int a, int b, int c) {
    return min({
        a + b + c,
        a + b - c,
        a + b * c,

        a - b + c,
        a - b - c,
        a - b * c,

        a * b + c,
        a * b - c,
        a * b * c,
    });
}

int solve(int a, int b, int c) {
    return min({
        solveSigns(a, b, c),
        solveSigns(a, c, b),

        solveSigns(b, a, c),
        solveSigns(b, c, a),

        solveSigns(c, a, b),
        solveSigns(c, b, a)
    });
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << endl;
    return 0;
}
