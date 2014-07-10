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

    if (0 !=  k) {
        printf("%d ", n - k);

        for (int i = 2; i <= (n - k); ++i) {
            printf("%d ", i-1);
        }

        for (int i = n - k + 1; i <= n; ++i) {
            printf("%d ", i);
        }
    } else {
        printf("%d ", n);
        for (int i = 2; i <= n; ++i) {
            printf("%d ", i-1);
        }
    }

    return 0;
}
