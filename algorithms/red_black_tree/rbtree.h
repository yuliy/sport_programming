#pragma once

enum EColour {
    C_BLACK,
    C_RED,
};

template<typename T>
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

template<typename T, typename TComparator = std::less<T> >
class TRBTree {
public:
    TNode<T> *Root;
    TComparator Cmp;
public:
    TNode<T> *Minimum(TNode<T> *x) const {
        while (x && x->Left)
            x = x->Left;
        return x;
    }

    TNode<T> *Maximum(TNode<T> *x) const {
        while (x && x->Right)
            x = x->Right;
        return x;
    }

    TNode<T> *Successor(TNode<T> *x) const {
        if (!x)
            return 0;

        if (x->Right)
            return Minimum(x->Right);

        TNode<T> *y = x->Parent;
        while (y && x == y->Right) {
            x = y;
            y = y->Parent;
        }
        return y;
    }

    void LeftRotate(TNode<T> *x) {
        TNode<T> *y = x->Right;
        x->Right = y->Left;
        if (y->Left != 0)
            y->Left->Parent = x;
        y->Parent = x->Parent;
        if (x->Parent == 0)
            Root = y;
        else if (x == x->Parent->Left)
            x->Parent->Left = y;
        else
            x->Parent->Right = y;
        y->Left = x;
        x->Parent = y;
    }

    void RightRotate(TNode<T> *y) {
        TNode<T> *x = y->Left;
        y->Left = x->Right;
        if (x->Right != 0)
            x->Right->Parent = y;
        x->Parent = y->Parent;
        if (y->Parent == 0)
            Root = x;
        else if (y == y->Parent->Left)
            y->Parent->Left = x;
        else
            y->Parent->Right = x;
        x->Right = y;
        y->Parent = x;
    }

    void Insert(TNode<T> *z) {
        TNode<T> *y = 0;
        TNode<T> *x = Root;
        while (x != 0) {
            y = x;
            x = Cmp(z->Key, x->Key) ? x->Left : x->Right;
        }

        z->Parent = y;
        if (y == 0)
            Root = z;
        else if (Cmp(z->Key, y->Key))
            y->Left = z;
        else
            y->Right = z;
        z->Left = 0;
        z->Right = 0;
        z->Colour = C_RED;
        InsertFixup(z);
    }

    void InsertFixup(TNode<T> *z) {
        if (Root == z) {
            z->Colour = C_BLACK;
            return;
        }

        while (z->Parent && z->Parent->Colour == C_RED) {
            // z is a left chilf of pp
            if (z->Parent == z->Parent->Parent->Left) {
                TNode<T> *y = z->Parent->Parent->Right;
                if (y && y->Colour == C_RED) {
                    z->Parent->Colour = C_BLACK;
                    y->Colour = C_BLACK;
                    z->Parent->Parent->Colour = C_RED;
                    z = z->Parent->Parent;
                } else {
                    if (z == z->Parent->Right) {
                        z = z->Parent;
                        LeftRotate(z);
                    } 
                    z->Parent->Colour = C_BLACK;
                    z->Parent->Parent->Colour = C_RED;
                    RightRotate(z->Parent->Parent);
                }
            // if is a right child of pp
            } else {
                TNode<T> *y = z->Parent->Parent->Left;
                if (y && y->Colour == C_RED) {
                    z->Parent->Colour = C_BLACK;
                    y->Colour = C_BLACK;
                    z->Parent->Parent->Colour = C_RED;
                    z = z->Parent->Parent;
                } else {
                    if (z == z->Parent->Left) {
                        z = z->Parent;
                        RightRotate(z);
                    }
                    z->Parent->Colour = C_BLACK;
                    z->Parent->Parent->Colour = C_RED;
                    LeftRotate(z->Parent->Parent);
                }
            }
        }
        Root->Colour = C_BLACK;
    }

    /*
    void Transplant(TNode<T> *u, TNode<T> *v) {
        if (u->Parent == 0)
            Root = v;
        else if (u == u->Parent->Left)
            u->Parent->Left = v;
        else
            u->Parent->Right = v;

        if (v)
            v->Parent = u->Parent;
    }
    */

    TNode<T> *Delete(TNode<T> *z) {
        TNode<T> *y = (z->Left == 0 || z->Right == 0) ? z : Successor(z);
        TNode<T> *x = (y->Left) ? y->Left : y->Right;
        x->Parent = y->Parent;

        if (y->Parent == 0) {
            Root = x;
        } else {
            if (y == y->Parent->Left)
                y->Parent->Left = x;
            else
                y->Parent->Right = x;
        }

        if (y != z) {
            z->Key = y->Key;
            // ...
        }

        if (y->Colour == C_BLACK)
            DeleteFixup(x);

        return y;
    /*
        TNode<T> *y = z;
        TNode<T> *x = 0;
        EColour yOriginalColour = y->Colour;
        if (z->Left == 0) {
            x = z->Right;
            Transplant(z, z->Right);
        } else if (z->Right == 0) {
            x = z->Left;
            Transplant(z, z->Left);
        } else {
            y = TreeMinimum(z->Right);
            yOriginalColour = y->Colour;
            x = y->Right;

            if (y->Parent == z) {
                x->Parent = y
            } else {
                Transplant(y, y->Right);
                y->Right = z->Right;
                y->Right->Parent = y;
            }

            Transplant(z, y);
            y->Left = z->Left;
            y->Left->Parent = y;
            y->Colour = z->Colour;
        }

        if (yOriginalColour == C_BLACK)
            DeleteFixup(x);
    */
    }

    void DeleteFixup(TNode<T> *x) {
        //
    }
public:
    TRBTree()
        : Cmp(TComparator())
        , Root(0) {
     }

    TRBTree(TComparator cmp)
        : Cmp(cmp)
        , Root(0) {
    }
};
