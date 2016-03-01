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

double CalcX2(double k1, double k2, double k3) {
    const double num = (1 + k2) * (1 + k3) + (1 + k1) * (1 + k3) + (1 + k2) * (1 + k1);
    const double den = (1 + k1) * (1 + k3);
    return 1000 * den / num;
}

int main() {
    double k1, k2, k3;
    cin >> k1 >> k2 >> k3;


    const double x2 = CalcX2(k1, k2, k3);
    const double x1 = (1 + k2) * x2 / (1 + k1);
    const double x3 = (1 + k2) * x2 / (1 + k3);

    //const double P = k1 * x1 - x2 - x3;

    const double res = min(k1*x1, min(k2*x2, k3*x3));
    //cout << round(P) << endl;
    cout << k1 * x1 << endl
        << k2 * x2 << endl
        << k3 * x3 << endl;
    cout << res << endl;

    return 0;
}
