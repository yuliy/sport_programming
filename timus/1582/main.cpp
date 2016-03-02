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

int main() {
    double k1, k2, k3;
    cin >> k1 >> k2 >> k3;

    //const double x1 = 1000.0 / (1 + k1/k2 + k1/k3);
    //const double x2 = k1 * x1 / k2;
    //const double x3 = k1 * x1 / k3;
    const double res = k1 * 1000.0 / (1 + k1/k2 + k1/k3);
    cout << round(res) << endl;

    return 0;
}
