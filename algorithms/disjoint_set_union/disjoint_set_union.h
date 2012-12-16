#pragma once

#include <list>
#include <vector>
#include <algorithm>
#include <boost/shared_ptr.hpp>

namespace ystd {

/**
  * TDisjointSetUnion
  *
  * This data structure implements disjoint set union via
  * disjoint set forest with 2 heuristics:
  *     1. union by rank (tree with lower rank is add as a child to root of tree with higher rank)
  *     2. path compression (all nodes are linked to root during FindSet operation)
  */
template<typename T>
class TDisjointSetUnion {
public:
    struct TNode {
        int Rank;
        TNode *Parent;
        T Value;

        TNode()
            : Rank(0)
            , Parent(this)
            , Value() {
        }

        explicit TNode(const T &val)
            : Rank(0)
            , Parent(this)
            , Value(val) {
        }
    };

public:
    typedef boost::shared_ptr<TNode> TPNode;
    typedef std::vector< TPNode > TPNodes;
    TPNodes PNodes;

public:
    TDisjointSetUnion() {
    }

    TNode *MakeSet(const T &val) {
        TPNode p(new TNode(val));
        p->Parent = p.get();
        p->Rank = 0;
        p->Value = val;
        PNodes.push_back(p);
        return p.get();
    }

    bool Union(TNode *x, TNode *y) {
        if (!x || !y)
            throw "Achtung!";

        TNode *sx = FindSet(x);
        TNode *sy = FindSet(y);
        if (!sx || !sy)
            throw "Achtung!";

        if (sx->Rank > sy->Rank) {
            sy->Parent = sx;
        } else {
            sx->Parent = sy;
            if (sx->Rank == sy->Rank)
                sy->Rank += 1;
        }

        return sx != sy;
    }

    bool Union(TPNode x, TPNode y) {
        return Union(x.get(), y.get());
    }

    TNode *FindSet(TNode *x) {
        if (!x)
            return 0;

        //if (x != x->Parent)
        //    x->Parent = FindSet(x->Parent);
        //return x->Parent;
        for (TNode *node = x; node != node->Parent; node = node->Parent)
            x->Parent = node;

        for (TNode *node = x; node != node->Parent; node = node->Parent) {
            node->Parent = x->Parent;
        }

        return x->Parent;
    }

    TNode *FindSet(TPNode x) {
        return FindSet(x.get());
    }
};

} // namespace ystd
