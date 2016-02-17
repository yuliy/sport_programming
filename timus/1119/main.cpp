#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <stdio.h>
#include <cmath>
#include <set>
using namespace std;

double Dist[1001][1001] = {0.0};
bool Flags[1001][1001] = {false};

double Min(double v1, double v2, double v3) {
    return min(v1, min(v2, v3));
}

static const double SQRT2 = 1.4142135623730951;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < K; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        Flags[x][y] = true;
    }

    for (int i = 0; i <= N; ++i) {
        Dist[0][i] = i * 100.0;
    }
    for (int i = 0; i <= M; ++i) {
        Dist[i][0] = i * 100.0;
    }

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            Dist[i][j] = Min(
                Dist[i-1][j] + 100,
                Dist[i][j-1] + 100,
                Flags[j][i] ? (Dist[i-1][j-1] + 100 * SQRT2) : 1e9
            );
        }
    }

    /*
    for (int i = 0; i <= M; ++i) {
        cout << "i = " << i << endl;
        for (int j = 0; j <= N; ++j) {
            cout << Dist[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    */

    cout << round(Dist[M][N]) << endl;

    return 0;
}
