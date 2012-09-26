#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

int A[1001][1001];
int D[1001][1001];
int F[1001][1001];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            D[i][j] = 0;
            F[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &(A[i][j]));
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int prev = -1;
            if (i == 1) {
                F[i][j] = 2; // R
                D[i][j] = D[i][j-1];
                prev = A[i][j-1];
            } else if (j == 1) {
                F[i][j] = 1; //D
                D[i][j] = D[i-1][j];
                prev = A[i-1][j];
            } else if (i > 1 && D[i-1][j] < D[i][j-1]) {
                F[i][j] = 1; //D
                D[i][j] = D[i-1][j];
                prev = A[i-1][j];
            } else {
                F[i][j] = 2; //R
                D[i][j] = D[i][j-1];
                prev = A[i][j-1];
            }

            if ((A[i][j] * prev) % 10 == 0)
                ++D[i][j];
        }
    }

    printf("%d\n", D[n][n] - 1);
    deque<int> path;
    for (int i = n, j = n; i > 1 || j > 1;) {
        path.push_front(F[i][j]);
        if (F[i][j] == 1)
            --i;
        else
            --j;
    }

    for (deque<int>::const_iterator iter = path.begin(); iter != path.end(); ++iter) {
        if (*iter == 1)
            printf("D");
        else
            printf("R");
    }
    printf("\n");
    return 0;
}
