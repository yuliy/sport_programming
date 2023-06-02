#include <vector>
#include <deque>
#include <iostream>

using Grid = vector<vector<int>>;
using AdjList = vector<int>;
using AdjLists = vector<AdjList>;
using Q = deque<int>;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const size_t n = grid.size();
        if (n == 1 && grid[0][0])
            return -1;

        AdjLists adj_lists(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[j][i]) {
                    adj_lists[j*n + i] = CreateAdjList(n, i, j, grid);
                    cout << "i=" << i << " j=" << j << endl; 
                }
            }
        }

        vector<int> visited(n * n);
        vector<int> depth(n * n);
        visited[0] = 1;
        depth[0] = 1;
        Q q;
        q.push_back(0);
        while (!q.empty()) {
            const int u = q.front();
            q.pop_front();
            const auto &lst = adj_lists[u];
            for (const auto v : lst) {
                if (!visited[v]) {
                    visited[v] = 1;
                    depth[v] = depth[u] + 1;
                    q.push_back(v);
                }
            }
        }

        return visited[n*n - 1] ? depth[n*n-1] : -1;
    }

private:
    static vector<int> CreateAdjList(int n, int i, int j, const Grid &grid) {
        AdjList res;
        CheckAppend(n, i-1, j-1, grid, res);
        CheckAppend(n, i,   j-1, grid, res);
        CheckAppend(n, i+1, j-1, grid, res);

        CheckAppend(n, i-1, j,   grid, res);
        CheckAppend(n, i+1, j,   grid, res);

        CheckAppend(n, i-1, j+1, grid, res);
        CheckAppend(n, i,   j+1, grid, res);
        CheckAppend(n, i+1, j+1, grid, res);
        return res;
    }

    static inline void CheckAppend(int n, int i, int j, const Grid &grid, AdjList &lst) {
        if ( (i >= 0) && (i < n) && (j >= 0) && (j < n) && !grid[j][i] )
            lst.push_back( j*n + i);
    }
};
