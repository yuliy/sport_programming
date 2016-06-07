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

using i64 = long long;

static void CalcEratosphenSieve(set<int>& res, int max) {
    vector<bool> sieve(2 * max, true);
    for (size_t i = 2; i < sieve.size(); ++i) {
        if (sieve[i]) {
            res.insert(i);
            for (size_t j = i * i; j < sieve.size(); j +=i) {
                sieve[j] = false;
            }
        }
    }
}

set<int> nums;

int n, m;
static const int MAX_SIZE = 500;
int arr[MAX_SIZE+1][MAX_SIZE+1];

int SolveRow(int row) {
    int res = 0;
    for (int j = 0; j < m; ++j) {
        auto it = nums.lower_bound(arr[row][j]);
        if (it == nums.end())
            throw "Logical error!";
        res += (*it - arr[row][j]);
    }
    return res;
}

int SolveColumn(int col) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        auto it = nums.lower_bound(arr[i][col]);
        if (it == nums.end())
            throw "Logical error!";
        res += (*it - arr[i][col]);
    }
    return res;
}

int main() {
    CalcEratosphenSieve(nums, 1e5);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }

    int res = 1e9;
    for (int i = 0; i < n; ++i) {
        res = min(res, SolveRow(i));
    }
    for (int j = 0; j < m; ++j) {
        res = min(res, SolveColumn(j));
    }
    cout << res << endl;
    return 0;
}
