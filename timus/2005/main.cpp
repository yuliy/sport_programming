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

int M[6][6] = {0};

int Solve(const vector<int>& path) {
    int res = 0;
    for (int i = 1; i < 5; ++i) {
        const int p = path[i-1];
        const int n = path[i];
        res += M[p][n];
    }
    return res;
}

const vector<vector<int>> PossiblePaths = {
    {1, 3, 2, 4, 5},
    {1, 3, 4, 2, 5},
    {1, 2, 3, 4, 5},
    {1, 4, 3, 2, 5}
};

int main() {
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            scanf("%d", &M[i][j]);
        }
    }

    int res = 1e9;
    vector<int> path;

    for (const auto& curPath : PossiblePaths) {
        const int curRes = Solve(curPath);
        if (curRes < res) {
            res = curRes;
            path = curPath;
        }
    }

    cout << res << endl;
    for (int i = 0; i < 5; ++i) {
        cout << path[i] << ' ';
    }
    cout << endl;

    return 0;
}
