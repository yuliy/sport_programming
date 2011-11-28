#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

struct TNode {
    TNode()
        : Value(-1)
        , Parent(0)
        , Left(0)
        , Right(0) {
    }

    explicit TNode(int val)
        : Value(val)
        , Parent(0)
        , Left(0)
        , Right(0) {
    }

    int Value;
    TNode *Parent;
    TNode *Left;
    TNode *Right;
};

static void Insert(TNode &root, TNode &node) {
    const int nv = node.Value;
    TNode *z = &root;
    //cout << "----" << endl;
    //cout << "nv=" << nv << endl;
    for (;;) {
        const int zv = z->Value;
        if (nv < zv) {
            if (z->Left == 0) {
                z->Left = &node;
                //cout << "left child of " << z->Value << endl;
                break;
            }
            z = z->Left;
        } else {
            if (z->Right == 0) {
                z->Right = &node;
                //cout << "right child of " << z->Value << endl;
                break;
            }
            z = z->Right;
        }
    }
}

static void RLP(const TNode &node, vector<int> &res) {
    if (node.Right)
        RLP(*(node.Right), res);
    if (node.Left)
        RLP(*(node.Left), res);
    //printf("%d ", node.Value);
    res.push_back(node.Value);
}

int main() {
    int N;
    scanf("%d", &N);
    vector<TNode> v;
    for (int i = 0; i < N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        v.push_back(TNode(tmp));
    }

    vector<TNode>::reverse_iterator iter = v.rbegin();
    TNode &root = *iter;
    ++iter;

    for (vector<TNode>::reverse_iterator end = v.rend(); iter != end; ++iter)
        Insert(root, *iter);

    vector<int> res;
    RLP(root, res);
    const size_t cnt = res.size();
    for (size_t i = 0; i < cnt; ++i) {
        printf("%d", res[i]);
        if (i < (cnt-1))
            printf(" ");
    }

    return 0;
}
