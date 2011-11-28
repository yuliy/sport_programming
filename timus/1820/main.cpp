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
    int n, k;
    cin >> n >> k;

    int res;
    if (n != 1) {
        res = (2*n) / k;
        if ((2*n) % k)
            ++res;
    } else
        res = 2;

    cout << res << endl;

    return 0;
}
