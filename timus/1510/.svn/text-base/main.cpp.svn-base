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
    int N;
    scanf("%d", &N);

    map<int, int> m;
    for (int i = 0; i < N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        ++m[tmp];
    }

    int maxCnt = 0;
    int res = 0;
    for (map<int, int>::const_iterator iter = m.begin(), end = m.end(); iter != end; ++iter) {
        if (iter->second > maxCnt) {
            maxCnt = iter->second;
            res = iter->first;
        }
    }

    printf("%d\n", res);
    return 0;
}
