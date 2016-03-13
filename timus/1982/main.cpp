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

        deque<int> q;
        for (auto city : ECities) {
            q.push_back(city);
        }

        for (; !q.empty();) {
            //
        }
    }
private:
    int N;
    int K;
    vector<int> ECities;
    vector<vector<int>> Graph;
private:
    void Init() {
        cin >> N >> K;

        ECities.resize(K);
        for (int i = 0; i < K; ++i) {
            cin >> ECities[i];
            --ECities[i];
        }

        Graph.resize(N);
        for (int i = 0; i < N; ++i) {
            Graph[i].resize(N);
            for (int j = 0; j < N; ++j) {
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
