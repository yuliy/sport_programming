#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int N, Q;

const int MAX_N = 100;
int a[MAX_N+1][MAX_N+1];

static void Init() {
    for (int i = 0; i <= MAX_N; ++i) {
        for (int j = 0; j <= MAX_N; ++j) {
            a[i][j] = -1;
        }
    }
}

struct TNode {
    int Num;
    int Weight;
    TNode *Parent;
    TNode *Left;
    TNode *Right;

    TNode()
        : Weight(0)
        , Parent(0)
        , Left(0)
        , Right(0) {
    }
};

static void InitChildren(TNode &node, vector<TNode> &tree) {
    const int i = node.Num;
    for (int j = 1; j <= N; ++j) {
        if (node.Left && node.Right)
            break;

        if (a[i][j] != -1) {
            if (!node.Left) {
                node.Left = &tree[j];
                node.Left->Parent = &node;
            } else {
                node.Right = &tree[j];
                node.Right->Parent = &node;
            }
        }
    }
}

int main() {
    Init();

    scanf("%d %d\n", &N, &Q);
    for (int i = 1; i < N; ++i) {
        int from, to, w;
        scanf("%d %d %d\n", &from, &to, &w);
        a[from][to] = w;
        a[to][from] = w;
    }

    vector<TNode> tree(N+1);
    for (int i = 1; i <= N; ++i)
        tree[1].Num = i;
    InitChildren(tree[1], tree);

    //

    /*
    int p[MAX_N+1];
    for (int i = 0; i <= MAX_N; ++i)
        p[i] = 0;

    {
        vector<int> t;
        t.push_back(1);
        for (size_t k = 0; k < t.size(); ++k) {
            const size_t i = t[k];
            for (size_t j = 1; j < MAX_N; ++j) {
                if (a[i][j] >= 0) {
                    t.push_back(j);
                    a[j][i] = -1;
                }
            }
        }
    }
    */

    return 0;
}
