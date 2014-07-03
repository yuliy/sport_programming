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
    int n, m;
    cin >> n >> m;

    const int cnt = min(n, m);
    cout << (cnt + 1) << endl;
    for (int x = 0; x <= cnt; ++x) {
        const int y = cnt - x;
        cout << x << " " << y << endl;
    }
    return 0;
}
