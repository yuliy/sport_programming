#pragma once

template<typename T>
class TRBTree {
private:
    TNode *Root;
private:
    TRBTree(const TRBTree&); // TODO
    TRBTree& operator=(const TRBTree&); // TODO
public:
    enum EColour {
        C_BLACK,
        C_RED,
    };

    //template<typename T>
    struct TNode {
        EColour Colour;
        TNode *Parent, *Left, *Right;
        T Key;

        TNode()
            : Colour(C_BLACK)
            , Parent(0)
            , Left(0)
            , Right(0)
            , Key(T()) {
        }

        TNode(EColour colour, TNode *parent, TNode *left, TNode *right, const T &key)
            : Colour(colour)
            , Parent(parent)
            , Left(left)
            , Right(right)
            , Key(key) {
        }
    };
public:
    TRedBlackTree() : Root(0) {}

    /**
      * Searches node with a key given in a sub-tree with root x
      */
    const TNode* Search(const TNode *x, const T& key) const {
        while ((x != NULL) && (key != x->Key))
            x = (key < x->Key) ? x->Left : x->Right;
        return x;
    }

    /**
      * Returns node with a minimum key in a sub-tree with root x
      */
    const TNode *Minimum(const TNode *x) const {
        if (x != NULL)
            while (x->Left != NULL)
                x = x->Left;
        return x;
    }

    /**
      * Returns node with a maximum key in a sub-tree with root x
      */
    const TNode *Maximum(const TNode *x) const {
        if (x != NULL)
            while (x->Right != NULL)
                x = x->Right;
        return x;
    }

    /**
      * Returns successor of node x in inorder-tree-walk
      */
    const TNode *Successor(const TNode *x) const {
        if (x == NULL)
            return NULL;
        if (x->Right != NULL)
            return Minimum(x->Right);
        const TNode *y = x->Parent;
        while ((y != NULL) && (x == y->Right)) {
            x = y;
            y = y->Parent;
        }
        return y;
    }

    /**
      * Returns predecessor of node x in inorder-tree-walk
      */
    const TNode *Predecessor(const TNode *x) const {
        if (x == NULL)
            return NULL;
        if (x->Left != NULL)
            return Maximum(x->Left);
        const TNode *y = x->Parent;
        while ((y != NULL) && (x == y->Left)) {
            x = y;
            y = y->Parent;
        }
        return y;
    }

    /**
      * Inserts element z into the binary search tree without rebalancing the tree
      */
    void SimpleInsert(TNode *z) {
        // TODO
    }

    /**
      * Deletes element z from the binary search tree without rebalancing the tree
      */
    void SimpleDelete(TNode *z) {
        // TODO
    }
};
