#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);

    const double l = a * 0.01;
    const double h = b * 0.01;

    if (h <= 0.5 * l) {
        cout << "butter" << endl;
        return 0;
    }

    const double t = sqrt(2.0*(h-l*0.5)/9.81);
    const double c = t * w - floor(t * w);
    cout << c << endl;
    if (c < 0.25 || c >= 0.75)
        cout << "butter" << endl;
    else
        cout << "bread" << endl;

    return 0;
}
