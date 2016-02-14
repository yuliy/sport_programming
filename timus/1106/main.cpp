#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
using namespace std;

using TAdjList = vector<int>;
using TGraph = vector<TAdjList>;

class TApplication {
public:
    void Run() {
        Init();

        for (int i = 0; i < N; ++i) {
            if (!Visited[i])
                BFS(i);
        }

        /*
        cout << "Depths:" << endl;
        for (int i = 0; i < N; ++i) {
            cout << (i + 1) << " - " << Depth[i] << endl;
        }
        cout << endl;
        */

        vector<int> res = CalcResult();
        PrintResult(res);
    }
private:
    int N;
    vector<bool> Visited;
    vector<int> Depth;
    TGraph Graph;
private:
    void Init() {
        scanf("%d", &N);
        Graph.resize(N);
        Visited.resize(N);
        Depth.resize(N);

        for (int from = 0; from < N; ++from) {
            for (;;) {
                int to;
                scanf("%d", &to);
                if (to == 0)
                    break;

                Graph[from].push_back(--to);
            }
        }
    }

    void BFS(int startVertex) {
        Visited[startVertex] = true;
        Depth[startVertex] = 0;

        deque<int> q;
        q.push_back(startVertex);

        while (!q.empty()) {
            const int from = q.front();
            const int depth = Depth[from];
            const TAdjList& adjList = Graph[from];
            for (const auto to : adjList) {
                if (!Visited[to]) {
                    Visited[to] = true;
                    Depth[to] = depth + 1;
                    q.push_back(to);
                }
            }

            q.pop_front();
        }
    }

    vector<int> CalcResult() {
        vector<int> res;
        for (int i = 0; i < N; ++i) {
            if (Depth[i] == -1)
                return vector<int>();

            if (Depth[i] % 2)
                res.push_back(i);
        }
        return res;
    }

    void PrintResult(const vector<int>& res) {
        if (res.empty()) {
            cout << "0" << endl;
        } else {
            cout << res.size() << endl;
            for (auto v : res) {
                cout << (v + 1) << ' ';
            }
            cout << endl;
        }
    }
};

int main() {
    TApplication app;
    app.Run();
    return 0;
}
