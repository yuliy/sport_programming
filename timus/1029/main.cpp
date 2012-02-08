#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int M, N;
int a[101][501];
int d[101][501];
int p[101][501];
//vector<int> tmpvec(501);
//vector< vector<int> > a;
//vector< vector<int> > d;
//vector< vector<int> > p;

static void Init() {
    /*
    for (int i = 0; i <= 100; ++i) {
        a.push_back(tmpvec);
        d.push_back(tmpvec);
        p.push_back(tmpvec);
    }
    */

    scanf("%d %d", &M, &N);
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &(a[i][j]));
            d[i][j] = 2e9;
            p[i][j] = -1;
        }
    }

    // Initializing dynamics
    for (int j = 1; j <= N; ++j)
        d[1][j] = a[1][j];
}

int main() {
    Init();

    for (int i = 2; i <= M; ++i) {
        // left to right
        for (int j = 1; j <= N; ++j) {
            int &curd = d[i][j];
            int &curp = p[i][j];

            const int t = a[i][j] + d[i-1][j];
            if (t < curd) {
                curd = t;
                curp = j;
            }

            if (j > 1) {
                const int t = a[i][j] + d[i][j-1];
                if (t < curd) {
                    curd = t;
                    curp = p[i][j-1];
                }
            }
        }

        // right to left
        for (int j = N; j >= 1; --j) {
            int &curd = d[i][j];
            int &curp = p[i][j];

            const int t = a[i][j] + d[i-1][j];
            if (t < curd) {
                curd = t;
                curp = j;
            }

            if (j < N) {
                const int t = a[i][j] + d[i][j+1];
                if (t < curd) {
                    curd = t;
                    curp = p[i][j+1];
                }
            }
        }
    }

    /*
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j)
            cout << d[i][j] << "/" << p[i][j] << "\t";
        cout << endl;
    }
    */

    int minj = 0;
    int minCost = 1e9;
    for (int j = 1; j <= N; ++j) {
        if (d[M][j] < minCost) {
            minCost = d[M][j];
            minj = j;
        }
    }
    //cout << "minj=" << minj << endl;

    vector<int> path;
    path.push_back(minj);
    for (int i = M, j = minj; i >= 2; --i) {
        int nextj = p[i][j]; 
        while (nextj != j) {
            if (nextj > j)
                ++j;
            else
                --j;
            nextj = p[i][j];
            path.push_back(j);
        }
        path.push_back(nextj);
    }

    for (vector<int>::const_reverse_iterator iter = path.rbegin(), end = path.rend(); iter != end; ++iter)
        cout << *iter << " ";

    return 0;
}
