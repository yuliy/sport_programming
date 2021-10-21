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

using ui64 = unsigned long long;
using i64 = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ui64 n, k;
    cin >> n >> k;

    if (n & 1) {

        if (k <= (n/2+1)) {
            cout << (2*k-1) << endl;
        } else {
            k -= (n/2+1);
            cout << (2*k) << endl;
        }

    } else {

        if (k <= n/2) {
            cout << (2*k-1) << endl;
        } else {
            k -= n/2;
            cout << (2*k) << endl;
        }

    }

    return 0;
}
