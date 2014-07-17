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

int main() {
    int n;
    cin >> n;
    int x = 0;
    int y = n / 7 + 1;

    for (; y >= 0;) {
        const int tmp = 4 * x + 7 * y;
        if (tmp == n) {
            for (; x > 0; --x)
                cout << 4;
            for (; y > 0; --y)
                cout << 7;
            cout << endl;
            return 0;
        }

        if (tmp > n) {
            --y;
        } else {
            ++x;
        }
    }

    cout << "-1" << endl;
    return 0;
}
