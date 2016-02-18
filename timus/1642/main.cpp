#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

static const int UNDEFINED = 1e9;

int Solve(int n, int x, const vector<int>& a) {
    if (x < a[0]) {
        if (0 < a[0]) {
            return 2 * a[0] - x;
        } else {
            return UNDEFINED;
        }
    }

    if (x > a[n-1]) {
        if (a[n-1] < 0) {

        } else {

        }
    }

}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    vector<int> a(n);
    for(size_t i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());

    return 0;
}
