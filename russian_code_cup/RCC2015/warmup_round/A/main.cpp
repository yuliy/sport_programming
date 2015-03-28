#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

typedef unordered_map<int, int> TMap;

void pr(int colour, int count) {
    for (int i = 0; i < count; ++i) {
        printf("%d ", colour);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> a(n);
    TMap colour2count;
    for (int i = 0; i < n; ++i) {
        int colour;
        scanf("%d", &colour);
        ++colour2count[colour];
    }

    int to_choose = k;
    for (TMap::iterator it = colour2count.begin(); it != colour2count.end(); ++it) {
        if (0 == to_choose)
            break;
        pr(it->first, 1);
        it->second -= 1;
        --to_choose;
    }

    for (TMap::iterator it = colour2count.begin(); it != colour2count.end(); ++it) {
        if (0 == to_choose)
            break;
        if (it->second <= to_choose) {
            pr(it->first, it->second);
            to_choose -= it->second;
            it->second = 0;
        } else {
            pr(it->first, to_choose);
            it->second -= to_choose;
            to_choose = 0;
        }
    }

    return 0;
}
