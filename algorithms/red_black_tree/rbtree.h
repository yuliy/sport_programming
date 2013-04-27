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
