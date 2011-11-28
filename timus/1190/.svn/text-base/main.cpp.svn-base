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

    vector<int> v;

    for (int i = 0; i < N; ++i) {
        char name[32];
        int check;
        scanf("%s %d", name, &check);

        if (check) {
            int frac;
            scanf("%d", &frac);
            v.push_back(frac);
        } else {
            v.push_back(0);
        }
    }

    int last = 1;
    int min = 0;
    for (vector<int>::const_reverse_iterator iter = v.rbegin(), end = v.rend(); iter != end; ++iter) {
        const int tmp = *iter;
        if (tmp) {
            min += tmp;
            last = tmp;
        } else {
            min += last;
        }
    }

    int max = 0;
    last = 10000;
    for (vector<int>::const_iterator iter = v.begin(), end = v.end(); iter != end; ++iter) {
        const int tmp = *iter;
        if (tmp) {
            max += tmp;
            last = tmp;
        } else {
            max += last;
        }
    }

    //printf("%d %d\n", min, max);
    printf((min <= 10000 && max >= 10000) ? "YES\n" : "NO\n");

    return 0;
}
