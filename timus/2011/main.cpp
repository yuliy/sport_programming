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
    int n, a, b, c;
    cin >> n;

    a = b = c = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        if (tmp == 1)
            ++a;
        if (tmp == 2)
            ++b;
        if (tmp == 3)
            ++c;
    }

    if (a > c)
        swap(a, c);
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);

    if ((a != 0) && (b != 0) && (c != 0)) {
        cout << "Yes" << endl;
        return 0;
    }

    if (b == 0) {
        cout << "No" << endl;
        return 0;
    }

    if (b == 1) {
        if (c >= 5) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }

    if (c >= 2) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;

    return 0;
}
