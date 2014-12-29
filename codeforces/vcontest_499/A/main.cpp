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

//#define DEBUG

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    int res = 0;
    int pos = 1;
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        const int dist = l - pos;
        const int jumps = dist / x;
        const int shift = jumps * x;
#ifdef DEBUG
        cout << "__________________________" << endl;
        cout
            << "pos=" << pos << endl
            << "dist=" << dist << endl
            << "shift=" << shift << endl
            << "res=" << res << endl;
#endif

        pos += shift;

#ifdef DEBUG
        cout << endl
            << "pos=" << pos << endl
            << "res=" << res << endl;
#endif

        res += (r - pos + 1);
        pos = r + 1;

#ifdef DEBUG
        cout << endl
            << "pos=" << pos << endl
            << "res=" << res << endl;
#endif
    }

    printf("%d\n", res);
    return 0;
}
