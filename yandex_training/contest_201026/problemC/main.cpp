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
    int n, k;
    cin >> n >> k;
    if (n == k) {
        cout << "-1" << endl;
        return 0;
    }

    if (0 !=  k)
    printf("%d ", k);
    for (int i = 2; i <= k; ++i) {
        printf("%d ", i-1);
    }
    for (int i = k+1; i <= n; ++i) {
        printf("%d ", i);
    }

    return 0;
}
