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
    int M, N;
    scanf("%d %d", &M, &N);

    //long long a[101][501];
    vector< vector<long long> > a;
    vector<long long> tmpvec(501);
    for (int i = 0; i <= 100; ++i)
        a.push_back(tmpvec);

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf("%lld", &(a[i][j]));
        }
    }

    //long long d[101][501];
    //long long p[101][501];
    vector< vector<long long> > d;
    vector< vector<long long> > p;
    for (int i = 0; i <= 100; ++i) {
        d.push_back(tmpvec);
        p.push_back(tmpvec);
    }

    for (int j = 1; j <= N; ++j) {
        d[1][j] = a[1][j];
        p[1][j] = -1;
    }

    for (int i = 2; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            d[i][j] = a[i][j] + d[i-1][j];
            p[i][j] = j;
            if (j > 1) {
                const long long t = a[i][j] + a[i][j-1] + d[i-1][j-1];
                if (t < d[i][j]) {
                    d[i][j] = t;
                    p[i][j] = j-1;
                }
            }

            if (j < N) {
                const long long t = a[i][j] + a[i][j+1] + d[i-1][j+1];
                if (t < d[i][j]) {
                    d[i][j] = t;
                    p[i][j] = j+1;
                }
            }
        }
    }

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            cout << d[i][j] << "/" << p[i][j] << "\t";
        }
        cout << endl;
    }

    int minj = 0;
    long long minCost = 10LL*1000000000LL;
    for (int j = 1; j <= N; ++j) {
        if (d[M][j] < minCost) {
            minCost = d[M][j];
            minj = j;
        }
    }
    cout << minj << endl;

    vector<int> path;
    path.push_back(minj);
    for (int i = M, j = minj; i >= 2; --i) {
        const int t = p[i][j];
        //path.push_back(t);
        //if (j != t)
        //    path.push_back(t);
        j = t;
    }

    for (vector<int>::const_reverse_iterator iter = path.rbegin(), end = path.rend(); iter != end; ++iter)
        cout << *iter << " ";

    return 0;
}
