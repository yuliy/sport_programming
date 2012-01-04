#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int N, M, Q;

struct TNode {
    //int Num;
    TNode *Parent;
    int Rank;

    TNode()
        : Parent(0)
        , Rank(0) {
    }
};

struct TEdge {
    TNode *From;
    TNode *To;
    bool IsInQ;

    TEdge()
        : From(0)
        , To(0)
        , IsInQ(false) {
    }

    /*TEdge(const TNode *from, const TNode *to)
        : From(from)
        , To(to)
        , IsInQ(false) {
    }*/
};

struct TDisjointSet {
    //list<TNode*> Sets;
    int ConnectedComponentsCount;

    TDisjointSet(vector<TNode> &nodes) {
        ConnectedComponentsCount = nodes.size();
        //for (vector<TNode>::iterator iter = nodes.begin(), end = nodes.end(); iter != end; ++iter)
        //    Sets.push_back(&*iter);
    }

    TNode *FindSetRoot(TNode *node) {
        if (node != node->Parent)
            node->Parent = FindSetRoot(node->Parent);
        return node->Parent;
    }

    void UnionRoots(TNode *r1, TNode *r2) {
        --ConnectedComponentsCount;
        if (r1->Rank > r2->Rank)
            r2->Parent = r1;
        else {
            r1->Parent = r2;
            if (r1->Rank == r2->Rank)
                ++(r2->Rank);
        }
    }

    void Process(TEdge &edge) {
        TNode *fromRoot = FindSetRoot(edge.From);
        TNode *toRoot = FindSetRoot(edge.To);
        if (fromRoot != toRoot)
            UnionRoots(fromRoot, toRoot);
        //cout << ConnectedComponentsCount << endl;
    }
};

int main() {
    // M, N, ...
    scanf("%d %d\n", &N, &M);

    vector<TNode> nodes(N);
    for (vector<TNode>::iterator iter = nodes.begin(), end = nodes.end(); iter != end; ++iter)
        iter->Parent = &*iter;

    vector<TEdge> edges(M);
    for (int i = 0; i < M; ++i) {
        int from, to;
        scanf("%d %d\n", &from, &to);
        TEdge &edge = edges[i];
        edge.From = &(nodes[from-1]);
        edge.To = &(nodes[to-1]);
    }

    // Q, ...
    scanf("%d\n", &Q);
    vector<TEdge*> qedges(Q);
    for (int i = 0; i < Q; ++i) {
        int qnum;
        scanf("%d", &qnum); 
        TEdge &qedge = edges[qnum-1];
        qedge.IsInQ = true;
        qedges[i] = &qedge;
    }

    //
    TDisjointSet ds(nodes);

    //
    for (vector<TEdge>::iterator iter = edges.begin(), end = edges.end(); iter != end; ++iter) {
        TEdge &edge = *iter;
        if (edge.IsInQ)
            continue;
        ds.Process(edge);
    }

    vector<int> result;
    for (vector<TEdge*>::reverse_iterator iter = qedges.rbegin(), end = qedges.rend(); iter != end; ++iter) {
        TEdge &edge = **iter;
        result.push_back(ds.ConnectedComponentsCount);
        ds.Process(edge);
    }

    for (vector<int>::const_reverse_iterator iter = result.rbegin(), end = result.rend(); iter != end; ++iter)
        printf("%d ", *iter);
    printf("\n");

    return 0;
}
