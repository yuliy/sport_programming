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

int N;
bool HasZero = false;
int ZeroI = -1;
int ZeroJ = -1;

const int SIZE = 1001;
int D2[SIZE][SIZE];
int D5[SIZE][SIZE];

int C2[SIZE][SIZE];
int C5[SIZE][SIZE];

int P2[SIZE][SIZE];
int P5[SIZE][SIZE];

const int DOWN = 1;
const int RIGHT = 2;

static void Init() {
    scanf("%d", &N);
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <=N; ++j) {
            D2[i][j] = D5[i][j] = C2[i][j] = C5[i][j] = P2[i][j] = P5[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int num;
            scanf("%d", &num);

            if (num == 0) {
                HasZero = true;
                ZeroI = i;
                ZeroJ = j;
            }

            for (; num && (num % 2 == 0); ++D2[i][j])
                num /= 2;
            for (; num && (num % 5 == 0); ++D5[i][j])
                num /= 5;
        }
    }
}

static void CalcCountsAndPaths(int **C, int **P) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == 1) {
                C[i][j] += C[i][j-1];
                P[i][j] = RIGHT;
            } else if (j == 1) {
                C[i][j] += C[i-1][j];
                P[i][j] = DOWN;
            } else if (C[i-1][j] < C[i][j-1]) {
                C[i][j] += C[i-1][j];
                P[i][j] = DOWN;
            } else {
                C[i][j] += C[i][j-1];
                P[i][j] = RIGHT;
            }
        }
    }
}

int main() {
    Init();

    CalcCountsAndPaths(C2, P2);
    CalcCountsAndPaths(C5, P5);

    return 0;
}

/*
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
*/
