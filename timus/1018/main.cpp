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

    int ChildrenCnt() const {
        int res = 0;
        if (Left)
            ++res;
        if (Right)
            ++res;
        return res;
    }
};

static void InitChildren(TNode &node, vector<TNode> &tree) {
    const int i = node.Num;
    for (int j = 1; j <= N; ++j) {
        //cout << i << "\t" << j << endl;
        if (node.Left && node.Right)
            break;

        if (a[j][i] >= 0) {
            if (node.Left == 0) {
                node.Left = &tree[j];
                node.Left->Parent = &node;
            } else {
                node.Right = &tree[j];
                node.Right->Parent = &node;
            }
        }
    }

    if (node.Left)
        InitChildren(*(node.Left), tree);
    if (node.Right)
        InitChildren(*(node.Right), tree);
}

/*static void InitWeight(TNode &node) {
    if (!node.Parent)
        return;

    const int i = node.Num;
    const int j = node.Parent->Num;
    node.Weight += a[i][j];
    InitWeight(*node.Parent);
}*/

list<TNode*>::iterator FindMin(list<TNode*> &leaves) {
    list<TNode*>::iterator res = leaves.begin();
    for (list<TNode*>::iterator iter = ++leaves.begin(), end = leaves.end(); iter != end; ++iter) {
        if ((*iter)->Weight < (*res)->Weight)
            res = iter;
    }
    return res;
}

int main() {
    Init();

    // reading input
    scanf("%d %d\n", &N, &Q);
    for (int i = 1; i < N; ++i) {
        int from, to, w;
        scanf("%d %d %d\n", &from, &to, &w);
        a[from][to] = w;
        a[to][from] = w;
    }

    {
        vector<int> t;
        t.push_back(1);
        for (size_t k = 0; k < t.size(); ++k) {
            const size_t i = t[k];
            for (size_t j = 1; j < (size_t)MAX_N; ++j) {
                if (a[i][j] >= 0) {
                    t.push_back(j);
                    a[j][i] = -1;
                }
            }
        }
    }

    // building tree
    vector<TNode> tree(N+1);
    for (int i = 0; i <= N; ++i)
        tree[i].Num = i;
    InitChildren(tree[1], tree);

    //
    //for (vector<TNode>::iterator iter = tree.begin(), end = tree.end(); iter != end; ++iter)
    //    InitWeight(*iter);
    int res = 0;
    for (vector<TNode>::iterator iter = tree.begin(), end = tree.end(); iter != end; ++iter) {
        if (iter->Parent == 0)
            continue;
        const int i = iter->Num;
        const int j = iter->Parent->Num;
        iter->Weight = a[j][i];
        res += a[j][i];
    }

    // searching leaves
    list<TNode*> leaves;
    for (vector<TNode>::iterator iter = tree.begin(), end = tree.end(); iter != end; ++iter) {
        if (iter->Left == 0 && iter->Right == 0)
            leaves.push_back(&*iter);
    }

    //
    for (int i = 0; i < (N-Q); ++i) {
        cout << "Q=" << i << "\tleaves.cnt=" << leaves.size() << endl;
        list<TNode*>::iterator miter = FindMin(leaves);
        cout << "(1)" << endl;
        TNode &node = **miter;
        cout << "(2)" << endl;
        cout << "res=" << res << endl;
        cout << "weight=" << node.Weight << endl;
        res -= node.Weight;
        cout << "(3)" << endl;
        if (node.Parent->ChildrenCnt() == 2) {
            cout << "(4)" << endl;
            leaves.erase(miter);
        } else {
            cout << "(5)" << endl;
            *miter = node.Parent;
        }
        cout << "(6)" << endl;
        cout << "res=" << res << endl;
    }

    printf("%d\n", res);

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
