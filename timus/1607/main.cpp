#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int p1, d1, p2, d2;
    cin >> p1 >> d1 >> p2 >> d2;

    bool flag = true;
    for (; p1 < p2; ) {
        if (flag) {
            p1 += d1;
        } else {
            p2 -= d2;
        }
        flag = !flag;
    }

    if (flag)
        cout << p1 << endl;
    else
        cout << p2 << endl;

    return 0;
}
