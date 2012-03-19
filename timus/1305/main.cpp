#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

struct TPoint {
    double X;
    double Y;

    TPoint(double x = 0.0, double y = 0.0) : X(x), Y(y) {
    }
};

typedef vector<TPoint> TPoints;

template<typename T, typename U>
struct TFirstComparator {
    bool operator()(const pair<T, U> &lhs, const pair<T, U> &rhs) const {
        return lhs.first < rhs.first;
    }
};


static int FindStartPoint(const TPoints &v) {
    int res = 0;
    int miny = v[0].Y;
    int minx = v[0].X;
    for (int i = 1; i < N; ++i) {
        if (v[i].Y < miny ||
            (v[i].Y == miny && v[i].X < minx)) {
            res = i;
            miny = v[i].Y;
            minx = v[i].X;
        }
    }
    return res;
}

int main() {
    int N;
    scanf("%d", &N);

    TPoints points;
    for (int i = 0; i < N; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        points.push_back(TPoint(x, y));
    }

    const int idx = FindStartPoint(points);

    vector< pair<double, int> > v;
    for (int i = 0; i < N; ++i) {
        if (i == idx)
            continue;

        const double dx = points[i].X - points[idx].X;
        const double dy = points[i].Y - points[idx].Y;
        v.push_back( make_pair((dx == 0.0) ? 0.0 : (dx / dy), i) );
    }

    std::sort(v.begin(), v.end(), TFirstComparator<double, int>());

    vector<int> st;
    st.push_back(idx);
    st.push_back(v[0].second);
    st.push_back(v[1].second);

    return 0;
}
