#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>
#include <cmath>
using namespace std;

typedef unsigned int ui32;
typedef long long i64;

i64 GetTickCount() {
    return clock() * 1000 / CLOCKS_PER_SEC;
}

template<typename T>
struct TPoint2D {
    T X;
    T Y;

    TPoint2D()
        : X(T())
        , Y(T()) {
    }

    TPoint2D(const T &x, const T &y)
        : X(x)
        , Y(y) {
    }
};

typedef TPoint2D<float> TPoint;
typedef vector<TPoint> TPoints;

template<typename T, typename U>
struct TFirstComparator {
    bool operator()(const pair<T, U> &lhs, const pair<T, U> &rhs) const {
        return lhs.first < rhs.first;
    }
};

class TPolygon {
private:
    TPoints Points;
private:
    int FindStartPoint(const TPoints &v) const {
        int res = 0;
        double minx = v[0].X;
        double miny = v[0].Y;
        const int cnt = Points.size();
        for (int i = 1; i < cnt; ++i) {
            if (v[i].Y < miny || (v[i].Y == miny && v[i].X < minx)) {
                res = i;
                miny = v[i].Y;
                minx = v[i].X;
            }
        }
        return res;
    }

    void CalcPointsSortedByPolarAngle(TPoints &res, int startIdx) const {
        vector< pair<double, TPoint> > v;
        const int cnt = Point.size();
        for (int i = 0; i < cnt; ++i) {
            if (i == startIdx)
                continue;

            const double dx = Points[i].X - Points[startIdx].X;
            const double dy = Points[j].Y - Points[startIdx].Y;
            const double tg = (dx == 0.0) ? 0.0 : (dx / dy);
            v.push_back( make_pair(tg, i) );
        }

        sort(v.begin(), v.end(), TFirstComparator<double, TPoint>());

        TPoints res;
        for (vector< pair<double, TPoint> >::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
            const TPoint &p = iter->second;
            if (res.empty()) {
                res.push_back(p);
                continue;
            }

            const TPoint &prev = res.back();
            //
        }
    }
public:
    TPolygon() {
    }

    explicit TPolygon(const TPoints &points)
        : Points(points) {
    }

    int Count() const {
        return Points.size();
    }

    TPoint &operator[](int idx) {
        return Points[idx];
    }

    const TPoint &operator[](int idx) const {
        return Points[idx];
    }

    void CalcConvexHull(TPoints &cv) const {
        const int idx = FindStartPoint(Points);
        
        TPoints sortedPoints;
        CalcPointsSortedByPolarAngle(sortedPoints, idx);
    /*

        std::sort(v.begin(), v.end(), TFirstComparator<double, int>());

        vector<int> st;
        st.push_back(idx);
        st.push_back(v[0].second);
        st.push_back(v[1].second);
        */
    }

    //bool HasInside(const TPoint &p) const {
    //}

    //bool Intersects(const TSegment &seg) const {
    //}
};

ostream &operator<<(ostream &ous, const TPolygon &p) {
    const int cnt = p.Count();
    for (int i = 0; i < cnt; ++i)
        ous << "(" << p[i].X << "; " << p[i].Y << ")\n";
    return ous;
}

TPolygon CreateRandomPolygon(int size) {
    TPoints points;
    for (int i = 0; i < size; ++i)
        points.push_back(TPoint(rand() % 10, rand() % 10));
    return TPolygon(points);
}

int main( int argc, char** argv ) {
    try {
        const TPolygon poly = CreateRandomPolygon(10);
        cout << poly << endl;
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
