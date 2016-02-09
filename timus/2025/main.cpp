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

int SolveSimple(int p, int s) {
    return p * p * s * (s - 1) / 2;
}

int Solve(int n, int k) {
    const int p = n / k;
    const int s = k - n % k;

    const int a = SolveSimple(p, s);
    const int b = SolveSimple(p + 1, k - s);
    const int c = p * (p + 1) * (k - s) * s;

    return a + b + c;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int n, k;
        cin >> n >> k;
        cout << Solve(n, k) << endl;
    }

    return 0;
}
