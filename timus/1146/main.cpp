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
    int N = 0;
    scanf("%d", &N);

    //
    int a[105][105];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &(a[i][j]));
        }
    }

    //
    for (int i = 0; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            a[i][j] += a[i][j-1];
        }
    }

    int res = -1000000000;
    for (int l = 0; l < N; ++l) {
        for (int r = l; r < N; ++r) {
            for (int t = 0; t < N; ++t) {
                //cout << "-----------" << endl;
                //cout << "l=" << l << "\tr=" << r << "\tt=" << t << endl;
                int sum = 0;
                for (int b = t; b < N; ++b) {
                    int rowSum = a[b][r];
                    if (l > 0)
                        rowSum -= a[b][l-1];
                    sum += rowSum;
                    //cout << "rowSum=" << rowSum << endl;
                    //cout << "b=" << b << "\tsum=" << sum << endl;
                    if (sum > res)
                        res = sum;
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}
