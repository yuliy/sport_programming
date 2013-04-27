#pragma once

#include <exception>

class TRBTException : public std::exception {
private:
    std::string Descr;
public:
    explicit TRBTException(const std::string &descr) : Descr(descr) {}
    explicit TRBTException(const char *descr) : Descr(descr) {}
    ~TRBTException() throw() {}
    const char *what() throw() { return Descr.c_str(); }
};

/**
  * TRBTree implements Red-Black Tree without iterators interface
  */
template<typename T>
class TRBTree {
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

        explicit TNode(const T &key)
            : TNode() {
            Key = key;
        }

        TNode(EColour colour, TNode *parent, TNode *left, TNode *right, const T &key)
            : Colour(colour)
            , Parent(parent)
            , Left(left)
            , Right(right)
            , Key(key) {
        }
    };
private:
    TNode *Root;
private:
    TRBTree(const TRBTree&); // TODO
    TRBTree& operator=(const TRBTree&); // TODO
public: // TODO
    /**
      * Inserts element z into the binary search tree without rebalancing the tree
      */
    void SimpleInsert(TNode *z) {
        if (z == NULL)
            throw TRBTException("TRBTree<T>::SimpleInsert received z == NULL!");

        const TNode *y = NULL;
        const TNode *x = this->Root;
        while (x != NULL) {
            y = x;
            x = (z->Key < x->Key) ? x->Left : x->Right;
        }
        z->Parent = y;
        if (y == NULL)
            this->Root = z;
        else if (z->Key < y->Key)
            y->Left = z;
        else
            y->Right = z;
    }

    /**
      * Replaces u with v, assuming that v is a child of u.
      * Warning! u->Left and u->Right are not initialized.
      */
    void Transplant(TNode *u, TNode *v) {
        if (u == NULL)
            throw TRBTException("TRBTree<T>::Transplant received u == NULL!");

        if (u->Parent == NULL)
            this->Root = v;
        else if (u == u->Parent->Left)
            u->Parent->Left = v;
        else
            u->Parent->Right = v;

        if (v != NULL)
            v->Parent = u->Parent;
    }

    /**
      * Deletes element z from the binary search tree without rebalancing the tree
      */
    void SimpleDelete(TNode *z) {
        if (z == NULL)
            throw TRBTException("TRBTree<T>::SimpleDelete received z == NULL!");

        if (z->Left == NULL)
            Transplant(z, z->Right);
        else if (z->Right == NULL)
            Transplant(z, z->Left);
        else {
            const TNode *y = Minimum(z->Right);
            if (y->Parent != z) {
                Transplant(y, y->Right);
                y->Right = z->Right;
                y->Right->Parent = y;
            }
            Transplant(z, y);
            y->Left = z->Left;
            y->Left->Parent = y;
        }
    }
public:
    TRBTree() : Root(0) {}

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
};
