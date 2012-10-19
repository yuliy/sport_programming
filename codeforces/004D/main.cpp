#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int n, w, h;
    scanf("%d %d %d", &n, &w, &h);

    typedef vector< pair<int, int> > TConverts;
    TConverts cs(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &(cs[i].first), &(cs[i].second));
    }
    return 0;
}
