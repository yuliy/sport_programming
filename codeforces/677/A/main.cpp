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
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, h;
    cin >> n >> h;

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        res += (ai > h) ? 2 : 1;
    }

    cout << res << endl;
    return 0;
}
