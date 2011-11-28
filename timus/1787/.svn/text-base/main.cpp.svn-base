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
    int k, n;
    cin >> k >> n;

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        res += a;
        res -= k;
        if (res < 0)
            res = 0;
    }

    cout << res << endl;

    return 0;
}
