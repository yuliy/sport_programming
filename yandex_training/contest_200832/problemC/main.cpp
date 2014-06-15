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

int solve(int li, int ri) {
    return 0;
}

int main() {
    string s;
    int q;
    cin >> s >> q;

    for (int i = 0; i < q; ++i) {
        int li, ri;
        scanf("%d %d", &li, &ri);
        const int res = solve(li, ri);
        printf("%d\n", res);
    }

    return 0;
}
