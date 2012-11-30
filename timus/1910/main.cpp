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
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    int idx = -1;
    int sum = -1;
    for (int i = 1; i < (n-1); ++i) {
        const int s = v[i-1] + v[i] + v[i+1];
        if (s > sum) {
            sum = s;
            idx = i;
        }
    }

    printf("%d %d\n", sum, idx+1);
    return 0;
}
