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
    map<int, int> m;

    for (int i = 0; i < 3; ++i) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int tmp;
            scanf("%d", &tmp);
            ++m[tmp];
        }
    }

    int res = 0;
    for (map<int, int>::const_iterator iter = m.begin(), end = m.end(); iter != end; ++iter)
        if (iter->second == 3)
            ++res;

    printf("%d\n", res);

    return 0;
}
