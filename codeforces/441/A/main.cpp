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
    int n, v;
    scanf("%d %d", &n, &v);
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        int ki;
        scanf("%d", &ki);
        bool ok = false;
        for (int j = 0; j < ki; ++j) {
            int tmp;
            scanf("%d", &tmp);
            if (v > tmp)
                ok = true;
        }
        if (ok)
            res.push_back(i+1);
    }

    const int p = res.size();
    printf("%d\n", p);
    for (int i = 0; i < p; ++i)
        printf("%d ", res[i]);

    return 0;
}
