#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <stdio.h>
#include <cmath>
#include <set>
using namespace std;

struct TCompare {
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) const {
        if (lhs.first != rhs.first)
            return lhs.first < rhs.first;
        return lhs.second < rhs.second;
    }
};

int main() {
    set< pair<int, int>, TCompare > dic;

    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        dic.insert( make_pair(x-1, y-1) );
    }

    const int MAX_SIZE = 1024;
    double prev[MAX_SIZE];
    double next[MAX_SIZE];
    for (int i = 0; i <= N; ++i) {
        prev[i] = 0.0;
        next[i] = 0.0;
    }

    const float diag = 100 * sqrt(2.0);
    for (int j = 0; j < M; ++j) {
        /*for (int i = 0; i <= N; ++i) {
            cout << prev[i] << " ";
        }
        cout << endl;*/

        for (int i = 0; i <= N; ++i) {
            const double cur = prev[i];
            double &right = prev[i+1];
            double &up = next[i];
            double &upright = next[i+1];
            {
                const double tmp = cur + 100;
                if (right == 0.0 || tmp < right)
                    right = tmp;
                if (up == 0.0 || tmp < up)
                    up = tmp;
            }

            if (dic.find(make_pair(i, j)) != dic.end()) {
                const double tmp = cur + diag;
                if (upright == 0.0 || tmp < upright)
                    upright = tmp;
            }
        }

        for (int i = 0; i <= N; ++i) {
            prev[i] = next[i];
            next[i] = 0.0;
        }
    }

    printf("%.f", prev[N]);
    return 0;
}
