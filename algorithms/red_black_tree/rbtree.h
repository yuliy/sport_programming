#pragma once

#include <exception>

class TRBTException : public std::exception {
private:
    std::string Descr;
public:
    explicit TRBTException(const std::string &descr) : Descr(descr) {}
    explicit TRBTException(const char *descr) : Descr(descr) {}
    ~TRBTException() throw() {}
    const char *what() const throw() { return Descr.c_str(); }
};

/**
  * TRBTree implements Red-Black Tree without iterators interface
  *
  *     Red-Black properties:
  *     1. Every node is either red or black
  *     2. The root is black
  *     3. Every leaf (NIL) is black
  *     4. If a node is red, then both its children are black
  *     5. For each node, all simple paths from the node to descendant leaves contain
  *         the same number of black nodes
  *
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
            : Colour(C_BLACK)
            , Parent(0)
            , Left(0)
            , Right(0)
            , Key(key) {
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
      * Destroys whole subtree tree with root node
      * Warning! Destroy assumes that node param is not NULL
      */
    void Destroy(TNode *node) {
        if (node->Left != NULL)
            Destroy(node->Left);
        if (node->Right != NULL)
            Destroy(node->Right);
        delete node;
    }

    /**
      * Inserts element z into the binary search tree without rebalancing the tree
      */
    void SimpleInsert(TNode *z) {
        if (z == NULL)
            throw TRBTException("TRBTree<T>::SimpleInsert received z == NULL!");

        TNode *y = NULL;
        TNode *x = this->Root;
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
    void SimpleDelete(const TNode *zz) {
        TNode *z = const_cast<TNode*>(zz);
        if (z == NULL)
            throw TRBTException("TRBTree<T>::SimpleDelete received z == NULL!");

        if (z->Left == NULL)
            Transplant(z, z->Right);
        else if (z->Right == NULL)
            Transplant(z, z->Left);
        else {
            TNode *y = const_cast<TNode*>( Minimum(z->Right) );
            if (y->Parent != z) {
                Transplant(y, y->Right);
                y->Right = z->Right;
                y->Right->Parent = y;
            }
            Transplant(z, y);
            y->Left = z->Left;
            y->Left->Parent = y;
        }

        delete z;
    }

    /**
      * Rotations:
      *
      *       |                           |
      *       y                           x
      *      / \       LeftRotate        / \
      *     x   G   <---------------    A   y
      *    / \      --------------->       / \
      *   A   B        RightRotate        B   G
      *
      */
    void LeftRotate(TNode *x) {
        TNode *y = x->Right;
        x->Right = y->Left;
        if (y->Left != NULL)
            y->Left->Parent = x;
        y->Parent = x->Parent;
        if (x->Parent == NULL)
            this->Root = y;
        else if (x == x->Parent->Left)
            x->Parent->Left = y;
        else
            x->Parent->Right = y;
        y->Left = x;
        x->Parent = y;
    }

    void RightRotate(TNode *y) {
        TNode *x = y->Left;
        y->Left = x->Right;
        if (x->Right != NULL)
            x->Right->Parent = y;
        x->Parent = y->Parent;
        if (y->Parent == NULL)
            this->Root = x;
        else if (y == y->Parent->Left)
            y->Parent->Left = x;
        else
            y->Parent->Right = x;
        x->Right = y;
        y->Parent = x;
    }

    /**
      * Implements rebalancing the tree after calling Insert procedure
      */
    void InsertFixup(TNode *x) {
        // TODO
    }

    /**
      * Implements rebalancing the tree after calling Delete procedure
      */
    void DeleteFixup(TNode *x) {
        // TODO
    }
public:
    TRBTree() : Root(0) {}
    ~TRBTree() {
        if (this->Root != NULL)
            Destroy(this->Root);
    }

    const TNode *GetRoot() const {
        return Root;
    }

    bool Empty() const {
        return Root == NULL;
    }

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
      * Returns node with a minimum key in a whole tree
      */
    const TNode *Minimum() const {
        return Minimum(Root);
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
      * Returns node with a maximum key in a whole tree
      */
    const TNode *Maximum() const {
        return Maximum(Root);
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
      * Inserts node into the tree and rebalances the tree
      */
    void Insert(TNode *z) {
        TNode *y = NULL;
        TNode *x = this->Root;
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

        z->Left = NULL;
        z->Right = NULL;
        z->Colour = C_RED;

        InsertFixup(z);
    }

    /**
      * Deletes node from the tree and rebalances the tree
      */
    void Delete(TNode *z) {
        // TODO
    }
};
