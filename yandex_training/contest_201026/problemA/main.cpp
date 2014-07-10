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
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    for (;;) {
        bool nothingToChange = true;
        sort(x.begin(), x.end());

        for (int i = n - 1; i > 0; --i) {
            if (x[i] > x[i-1]) {
                x[i] -= x[i-1];
                nothingToChange = false;
            }
        }

        if (nothingToChange)
            break;
    }

    cout << accumulate(x.begin(), x.end(), 0) << endl;
    return 0;
}
