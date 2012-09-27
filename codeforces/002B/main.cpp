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

static void CalcCountsAndPaths(int D[SIZE][SIZE], int C[SIZE][SIZE], int P[SIZE][SIZE]) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == 1) {
                C[i][j] = D[i][j] + C[i][j-1];
                P[i][j] = RIGHT;
            } else if (j == 1) {
                C[i][j] = D[i][j] + C[i-1][j];
                P[i][j] = DOWN;
            } else if (C[i-1][j] < C[i][j-1]) {
                C[i][j] = D[i][j] + C[i-1][j];
                P[i][j] = DOWN;
            } else {
                C[i][j] = D[i][j] + C[i][j-1];
                P[i][j] = RIGHT;
            }
        }
    }
}

static void FillPath(int P[SIZE][SIZE], deque<int> &path) {
    for (int i = N, j = N; i > 1 || j > 1;) {
        path.push_front(P[i][j]);
        if (P[i][j] == DOWN)
            --i;
        else
            --j;
    }
}

int main() {
    Init();

    CalcCountsAndPaths(D2, C2, P2);
    CalcCountsAndPaths(D5, C5, P5);

    if (HasZero && C2[N][N] >= 1 && C5[N][N] >= 1) {
        cout << "!!!!!!!!!!!!!" << endl;
        printf("1\n");
        for (int i = 1; i < ZeroJ; ++i)
            printf("R");
        for (int i = 1; i < N; ++i)
            printf("D");
        for (int i = ZeroJ; i < N; ++i)
            printf("R");
        printf("\n");
        return 0;
    }

    deque<int> path;
    if (C2[N][N] < C5[N][N])
        FillPath(P2, path);
    else
        FillPath(P5, path);

    printf("%d\n", min(C2[N][N], C5[N][N]));
    for (deque<int>::const_iterator iter = path.begin(); iter != path.end(); ++iter) {
        if (*iter == 1)
            printf("D");
        else
            printf("R");
    }
    printf("\n");
    return 0;
}
