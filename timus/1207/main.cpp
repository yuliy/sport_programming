#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <math.h>
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

int main() {
    int N;
    scanf("%d", &N);

    TPoints points;
    double minY = 2*10e9;
    int idx = -1;
    for (int i = 0; i < N; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);

        if (y < minY) {
            minY = y;
            idx = i;
        }

        points.push_back(TPoint(x, y));
    }

    vector< pair<double, int> > v;
    for (int i = 0; i < N; ++i) {
        if (i == idx)
            continue;

        const double dx = points[i].X - points[idx].X;
        const double dy = points[i].Y - points[idx].Y;
        v.push_back( make_pair((dx == 0.0) ? 0.0 : (dx / dy), i) );
    }

    std::sort(v.begin(), v.end(), TFirstComparator<double, int>());
    const int idx2 = v[v.size() / 2].second;
    printf("%d %d\n", idx+1, idx2+1);
    return 0;
}
