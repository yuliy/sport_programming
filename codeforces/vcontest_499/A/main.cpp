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
    int n, x;
    scanf("%d %d", &n, &x);
    vector< pair<int, int> > moments(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &moments[i].first, &moments[i].second);
    }
    return 0;
}
