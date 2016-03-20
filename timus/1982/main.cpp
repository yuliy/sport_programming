#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

class TApplication {
public:
    void Run() {
        Init();

        set<size_t> visitedVertices;
        visitedVertices.insert(ECities.begin(), ECities.end());

        multimap<size_t, pair<size_t, size_t>> edges;
        for (auto from : ECities) {
            for (size_t to = 0; to < N; ++to) {
                if (from == to)
                    continue;

                const size_t w = Graph[from][to];
                edges.insert(make_pair(
                    w,
                    make_pair(from, to)
                ));
            }
        }

        size_t res = 0;

        while (visitedVertices.size() < N) {
            const auto edgeIter = edges.begin();
            const size_t w = edgeIter->first;
            //const size_t from = edgeIter->second.first;
            const size_t to = edgeIter->second.second;
            edges.erase(edgeIter);

            if (visitedVertices.find(to) != visitedVertices.end()) {
                visitedVertices.insert(to);
                continue;
            }

            res += w;
            visitedVertices.insert(to);
            for (size_t nto = 0; nto < N; ++nto) {
                const size_t nw = Graph[to][nto];
                edges.insert(make_pair(
                    nw,
                    make_pair(to, nto)
                ));
            }

        }

        cout << res << endl;
    }
private:
    size_t N;
    size_t K;
    vector<size_t> ECities;
    vector<vector<size_t>> Graph;
private:
    void Init() {
        cin >> N >> K;

        ECities.resize(K);
        for (size_t i = 0; i < K; ++i) {
            cin >> ECities[i];
            --ECities[i];
        }

        Graph.resize(N);
        for (size_t i = 0; i < N; ++i) {
            Graph[i].resize(N);
            for (size_t j = 0; j < N; ++j) {
                cin >> Graph[i][j];
            }
        }
    }
};

int main() {
    TApplication app;
    app.Run();
    return 0;
}
