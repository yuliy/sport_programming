#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;

    if (x > 0 && y > 0) {
        if ((x + y) % 2)
            swap(x, y);
    }

    cout << x << ' ' << y << endl;
    return 0;
}
