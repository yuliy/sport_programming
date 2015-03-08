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
    if (n == 1) {
        cout << "yes" << endl
            << "1 1" << endl;
        return 0;
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int first = -1;
    int last = -1;
    bool yes = true;
    for (int i = 1; i < n; ++i) {
        if (a[i-1] > a[i]) {
            if (last != -1) {
                yes = false;
                break;
            }
            if (first == -1) {
                first = i;
            }
        } else {
            if ((first != -1) && (last == -1)) {
                last = i;
            }
        }
        //cout << a[i-1] << ": " << first << " - " << last << endl;
    }

    if (yes && (first != -1) && (last == -1)) {
        last = n;
    }

    if (yes && (last != -1) && (last != n) && (a[first-1] > a[last])) {
        yes = false;
    }

    if (yes && (last != -1) && (first > 1) && (a[last-1] < a[first-2])) {
        yes = false;
    }

    if (yes && first == -1) {
        first = 1;
        last = 1;
    }

    if (yes) {
        cout << "yes" << endl
            << first << " " << last << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
