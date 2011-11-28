#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

struct TPoint {
    double X;
    double Y;

    TPoint()
        : X(0)
        , Y(0) {
    }

    TPoint (double x, double y)
        : X(x)
        , Y(y) {
    }
};

typedef vector<TPoint> TPoints;

static double Dist(double x1, double y1, double x2, double y2) {
    const double dx = x2 - x1;
    const double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

static double CalcMinDistToVertices(double cx, double cy, const TPoints &points) {
    double res = 1000 * 1000 * 1000;
    for (TPoints::const_iterator iter = points.begin(), end = points.end(); iter != end; ++iter) {
        const double dist = Dist(cx, cy, iter->X, iter->Y);
        if (dist < res)
            res = dist;
    }
    return res;
}

static double CalcDistToEdge(double cx, double cy, double x1, double y1, double x2, double y2) {
    const double d1 = Dist(cx, cy, x1, y1);
    const double d2 = Dist(cx, cy, x2, y2);
    const double minD = min(d1, d2);
    const double maxD = max(d1, d2);

    if (x1 != x2) {
        const double A = 1;
        const double B = (y1 - y2) / (x2 - x1);
        const double C = -B * x1 - y1;
        const double d = abs(A * cx + B * cy + C) / sqrt(A*A + B*B);
        if (minD <= d && d <= maxD)
            return d;
        return 1000 * 1000 * 1000;
    } else {
        const double d = cx - x1;
        if (minD <= d && d <= maxD)
            return d;
        return 1000 * 1000 * 1000;
    }
}

static double CalcMinDistToEdges(double cx, double cy, const TPoints &points) {
    double res = 1000 * 1000 * 1000;
    for (TPoints::const_iterator iter = points.begin(), end = points.end(); iter != end; ++iter) {
        TPoints::const_iterator nextIter = iter;
        ++nextIter;
        if (nextIter == end)
            nextIter = points.begin();
        const double dist = CalcDistToEdge(cx, cy, iter->X, iter->Y, nextIter->X, nextIter->Y);
        if (dist < res)
            res = dist;
    }
    return res;
}

/*static bool DotsOnSameSideOfLine(double cx, double cy, double x1, double y1, double x2, double y2, double x, double y) {
    if (x1 != x2) {
        const double A = 1;
        const double B = (y1 - y2) / (x2 - x1);
        const double C = -B * x1 - y1;

        const double d1 = A * cx + B * cy + C;
        const double d2 = A * x + B * y + C;
        return ((d1 * d2) > 0.0);
    } else {
        const double d1 = cx - x1;
        const double d2 = x - x1;
        cout << d1 << '\t' << d2 << '\t' << (d1 * d2) << endl;
        return ((d1 * d2) > 0.0);
    }
}

static bool DotIsInsideTriangle(double cx, double cy,
                                double x1, double y1, double x2, double y2, double x3, double y3) {
    return (DotsOnSameSideOfLine(cx, cy, x1, y1, x2, y2, x3, y3) &&
            DotsOnSameSideOfLine(cx, cy, x1, y1, x3, y3, x2, y2) &&
            DotsOnSameSideOfLine(cx, cy, x2, y2, x3, y3, x1, y1));
}

static bool DotIsInsidePolygon(double cx, double cy, const TPoints &points) {
    const size_t cnt = points.size();
    const double x0 = points[0].X;
    const double y0 = points[0].Y;
    for (size_t i = 1; i < (cnt-2); ++i) 
        if (DotIsInsideTriangle(cx, cy, x0, y0, points[i].X, points[i].Y, points[i+1].X, points[i+1].Y))
            return true;
    return false;
}*/

static bool CheckOrientation(double cx, double cy, const TPoint &p1, const TPoint &p2) {
    const double x1 = p1.X;
    const double y1 = p1.Y;
    const double x2 = p2.X;
    const double y2 = p2.Y;

    if (x1 != x2) {
        const double A = 1.0;
        const double B = (y1 - y2) / (x2 - x1);
        const double C = -B * x1 - y1;
        const double d = A * cx + B * cy + C;
        return d > 0.0;
    } else {
        return cx < x1;
    }
}

static bool DotIsInsidePolygon(double cx, double cy, const TPoints &points) {
    const size_t cnt = points.size();
    for (size_t i = 0; i < (cnt-1); ++i) {
        const TPoint &p1 = points[i];
        const TPoint &p2 = points[i+1];
        if (!CheckOrientation(cx, cy, p1, p2))
            return false;
    }
    return true;
}

int main() {
    int cx, cy, N;
    scanf("%d %d %d", &cx, &cy, &N);
    TPoints points;
    for (int i = 0; i < N; ++i) {
        int tx, ty;
        scanf("%d %d", &tx, &ty);
        points.push_back(TPoint(tx, ty));
    }

    double res = 0.0;
    if (!DotIsInsidePolygon(cx, cy, points)) {
        const double minV = CalcMinDistToVertices(cx, cy, points);
        const double minE = CalcMinDistToEdges(cx, cy, points);
        res = min(minV, minE);
    }
    printf("%.3f\n", 2.0 * res);
    return 0;
}
