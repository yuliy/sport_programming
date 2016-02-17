#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
using namespace std;

bool EmptyCell[1001][1001] = {false};
int Dist[1001][1001] = {0};

int main() {
    int N, M, py, px, hy, hx;
    scanf("%d %d %d %d %d %d", &N, &M, &py, &px, &hy, &hx);

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j) {
            EmptyCell[i][j] = s[i] == '.';
        }
    }

    return 0;
}
