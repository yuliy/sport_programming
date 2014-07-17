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
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    const int max_last = a.size() - 1;
    int first = 0;
    int last = 0;
    int sum = a[0];
    int res = (sum <= t) ? 1 : 0;

    for (;;) {
        int prev_first = first;
        int prev_last = last;
        if (sum > t) {
            if (first < last || (first == last && last < max_last)) {
                sum -= a[first];
                ++first;
            }
        } else if (sum < t) {
            res = max(res, last - first + 1);
            if (last < max_last) {
                ++last;
                sum += a[last];
            }
        } else {
            res = max(res, last - first + 1);
            if (first < last)
                ++first;
        }

        //cout << first << "\t" << last << endl;
        if (prev_first == first && prev_last == last)
            break;
    }

    cout << res << endl;
    return 0;
}
