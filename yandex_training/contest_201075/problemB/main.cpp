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

enum EState {
    ST_NONE,
    ST_IN_SEQUENCE,
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int global_res = 0;
    for (;;) {
        vector<int> newa;
        n = a.size();

        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i-1] < a[i]) {
                newa.push_back(a[i-1]);
            } else {
                newa.push_back(a[i-1]);
                ++i;

                for (; i < n && a[i-1] > a[i]; ++i) {
                }
                int len = 0;
                for (; i < n && a[i-1] < a[i] && a[i] < newa.back(); ++i, ++len) {
                }
                res = max(res, len);
            }
        }

        cout << "-------------------" << endl;
        cout << "res: " << res << endl;
        for (vector<int>::const_iterator it = newa.begin(); it != newa.end(); ++it)
            cout << *it << " ";
        cout << endl;

        if (newa.size() == a.size())
            break;
        global_res += res;
        a.swap(newa);
    }

    cout << global_res << endl;
    return 0;
}
