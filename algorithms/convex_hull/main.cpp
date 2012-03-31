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
typedef vector< TPoint > TPoints;

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
        float minx = v[0].X;
        float miny = v[0].Y;
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
        const TPoint &sPoint = Points[startIdx];

        vector< pair<double, TPoint> > v;
        const int cnt = Points.size();
        for (int i = 0; i < cnt; ++i) {
            if (i == startIdx)
                continue;

            const double dx = Points[i].X - sPoint.X;
            const double dy = Points[i].Y - sPoint.Y;
            const double atg = (dy == 0.0) ? ((dx > 0.0) ? 1e9 : -1e9) : (dx / dy);
            v.push_back( make_pair(atg, Points[i]) );
        }

        sort(v.begin(), v.end(), TFirstComparator<double, TPoint>());

        double prev_atg = 0.0;
        for (vector< pair<double, TPoint> >::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
            const TPoint &p = iter->second;
            if (res.empty()) {
                res.push_back(p);
                prev_atg = iter->first;
                continue;
            }

            if (iter->first != prev_atg) {
                res.push_back(p);
            } else {
                const TPoint &prev = res.back();
                const double dd = (p.X - sPoint.X) * (p.X - sPoint.X) + (p.Y - sPoint.Y) * (p.Y - sPoint.Y);
                const double prev_dd = (prev.X - sPoint.X) * (prev.X - sPoint.X) + (prev.Y - sPoint.Y) * (prev.Y - sPoint.Y);
                if (dd > prev_dd)
                    res.back() = p;
            }

            prev_atg = iter->first;
        }
    }

    bool NonLeftTurn(const TPoint &p0, const TPoint &p1, const TPoint &p2) const {
        const TPoint a(p2.X - p0.X, p2.Y - p0.Y);
        const TPoint b(p1.X - p0.X, p2.Y - p0.Y);
        const float p = a.X * b.Y - b.X * a.Y;
        return p >= 0.0;
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

    void CalcConvexHull_Graham(TPolygon &ch) const {
        const int startIdx = FindStartPoint(Points);
        const TPoint &sPoint = Points[startIdx];
        
        TPoints sortedPoints;
        CalcPointsSortedByPolarAngle(sortedPoints, startIdx);

        vector<TPoint> st;
        st.push_back(sPoint);
        st.push_back(sortedPoints[0]);
        st.push_back(sortedPoints[1]);

        const int m = sortedPoints.size();
        for (int i = 2; i < m; ++i) {
            const TPoint &pi = sortedPoints[i];
            while ( NonLeftTurn(st[st.size()-2], st[st.size()-1], pi) )
                st.pop_back();
            st.push_back(pi);
        }

        ch = TPolygon(st);
    }

    /*
    void CalcConvexHull_Jarvis(TPoints &cv) const {
        
    }
    */

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
        TPolygon ch;
        poly.CalcConvexHull_Graham(ch);
        cout << "-----------------------------------" << endl
            << ch << endl;
    } catch (const exception &xcp) {
        cout << "An std::exception occured in main routine: " << xcp.what() << endl;
    } catch (...) {
        cout << "An unknown exception occured in main routine!" << endl;
    }

    return 0;
}
