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
#include <cmath>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    const int x1 = (x > 0 ? 1 : -1) * (abs(x) + abs(y));
    const int y1 = 0;
    const int x2 = 0;
    const int y2 = (y > 0 ? 1 : -1) * (abs(x) + abs(y));

    if (x1 < x2) {
        cout << x1 << " "
            << y1 << " "
            << x2 << " "
            << y2 << endl;
    } else {
        cout << x2 << " "
            << y2 << " "
            << x1 << " "
            << y1 << endl;
    }
    return 0;
}
