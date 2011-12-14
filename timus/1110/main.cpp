#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

const int MAX_POW = 1000;
const int MAX_X = 1000;
int POW[MAX_X][MAX_POW];

int N, M, Y;

static void Init() {
    for (int i = 0; i < M; ++i)
        POW[i][0] = 1;
    for (int n = 1; n <= N; ++n) {
        for (int i = 0; i < M; ++i) {
            POW[i][n] = POW[i][n-1] * i;
            POW[i][n] %= M;
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &Y);
    Init();

    bool nosolution = true;
    for (int i = 0; i < M; ++i) {
        if (POW[i][N] == Y) {
            printf("%d ", i);
            nosolution = false;
        }    
    }
    if (nosolution)
        printf("-1");
    printf("\n");

    return 0;
}
