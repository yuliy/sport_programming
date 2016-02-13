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

using TAdjList = unordered_set<string>;
using TGraph = unordered_map<string, TAdjList>;

class TApplication {
public:
    void Run() {
        Init();
        BFS();
        PrintResult();
    }
private:
    int N = 0;
    map<string, int> Player2Rank;
    TGraph Graph;
    unordered_set<string> Visited;
private:
    void Init() {
        scanf("%d", &N);

        for (int i = 0; i < N; ++i) {
            char buf1[256];
            char buf2[256];
            char buf3[256];
            scanf("%s %s %s", buf1, buf2, buf3);

            Player2Rank[buf1] = -1;
            Player2Rank[buf2] = -1;
            Player2Rank[buf3] = -1;

            AddEdge(buf1, buf2);
            AddEdge(buf1, buf3);
            AddEdge(buf2, buf3);
        }

    }

    void AddEdge(const char* p1, const char* p2) {
        Graph[p1].insert(p2);
        Graph[p2].insert(p1);
    }

    void BFS() {
        if (Player2Rank.find("Isenbaev") == Player2Rank.end())
            return;

        Player2Rank["Isenbaev"] = 0;
        Visited.insert("Isenbaev");

        deque<string> q;
        q.push_back("Isenbaev");

        while (!q.empty()) {
            const string& player = q.front();
            const int rank = Player2Rank[player];
            const TAdjList& adjList = Graph[player];
            for (const auto& p : adjList) {
                if (Visited.find(p) == Visited.end()) {
                    Player2Rank[p] = rank + 1;
                    q.push_back(p);
                    Visited.insert(p);
                }
            }

            q.pop_front();
        }
    }

    void PrintResult() {
        for (const auto& elem : Player2Rank) {
            cout << elem.first << ' ';
            if (elem.second == -1) {
                cout << "undefined" << endl;
            } else {
                cout << elem.second << endl;
            }
        }
    }
};

int main() {
    TApplication app;
    app.Run();
    return 0;
}
