#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>
#include <cmath>
using namespace std;

template<typename T>
struct TPoint2 {
    T X;
    T Y;

    TPoint2(const T &x, const T &y)
        : X(x)
        , Y(y) {
    }

    TPoint2(const TPoint2<T> &other)
        : X(other.X)
        , Y(other.Y) {
    }

    TPoint2<T> operator+(const TPoint2<T> &other) {
        TPoint2<T> res;
        res.X = X + other.X;
        res.Y = Y + other.Y;
        return res;
    }

    TPoint2<T> operator-(const TPoint2<T> &other) {
        TPoint2<T> res;
        res.X = X - other.X;
        res.Y = Y - other.Y;
        return res;
    }

};

typedef TPoint2<int> TPoint2i;
typedef TPoint2<float> TPoint2f;

/// Calculates 2D-variant of cross-product
template<typename T>
T CrossProduct(const TPoint2<T> &a, const TPoint2<T> &b) {
    return a.X * b.Y - a.Y * b.X;
}

/// Returns number > 0 if vector ac should be rotated counter-clockwise to get to vector ab,
/// returns number < 0 if vector ac should be rotated clockwise to get to vector ab.
/// 
/// Another interpretation:
///    Returns number > 0 if c is to the right side from line ab,
///    returns number < 0 if c is to the left side from line ab.
template<typename T>
T Direction(const TPoint2<T> &a, const TPoint2<T> &b, const TPoint2<T> &c) {
    return CrossProduct(c - a, b - a);
}

/// Returns true if point c lies on segment [a, b]
/// This routine assumes that all the three points lie on the same line
template<typename T>
bool OnSegment(const TPoint2<T> &a, const TPoint2<T> &b, const TPoint2<T> &c) {
    return  min(a.X, b.X) <= c.X &&
            c.X <= max(a.X, b.X) &&
            min(a.Y, b.Y) <= c.Y &&
            c.Y <= max(a.Y, b.Y);
}

/// Returns true if segment [p1, p2] intersects segment [p3, p4]
template<typename T>
bool SegmentsIntersect( const TPoint2<T> &p1, const TPoint2<T> &p2,
                        const TPoint2<T> &p3, const TPoint2<T> &p4) {
    const T d1 = Direction(p3, p4, p1);
    const T d2 = Direction(p3, p4, p2);
    const T d3 = Direction(p1, p2, p3);
    const T d4 = Direction(p1, p2, p4);

    if ( ((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
         ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)) )
        return true;

    if (d1 == 0 && OnSegment(p3, p4, p1))
        return true;
    if (d2 == 0 && OnSegment(p3, p4, p2))
        return true;
    if (d3 == 0 && OnSegment(p1, p2, p3))
        return true;
    if (d4 == 0 && OnSegment(p1, p2, p4))
        return true;

    return false;
}

int main( int argc, char** argv ) {
    try {
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
