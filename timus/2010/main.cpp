#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
using namespace std;

bool IsInCorner(int n, int x, int y) {
    return
        ((x == 1) || (x == n))
        &&
        ((y == 1) || (y == n));
}

int SolveKing(int n, int x, int y) {
    int res = 0;

    if (x > 1) ++res;
    if (y > 1) ++res;
    if (x < n) ++res;
    if (y < n) ++res;

    if (x > 1 && y > 1) ++res;
    if (x > 1 && y < n) ++res;
    if (x < n && y > 1) ++res;
    if (x < n && y < n) ++res;

    return res;
}

int SolveKnight(int n, int x, int y) {
    int res = 0;

    const int n1 = n - 1;

    if (x > 2 && y > 1) ++res;
    if (x > 1 && y > 2) ++res;
    if (x < n && y > 2) ++res;
    if (x < n1 && y > 1) ++res;

    if (x < n1 && y < n) ++res;
    if (x < n && y < n1) ++res;
    if (x > 1 && y < n1) ++res;
    if (x > 2 && y < n) ++res;

    return res;
}

int SolveBishop(int n, int x, int y) {
    return
        min(x-1, y-1)
      + min(n-x, y-1)
      + min(n-x, n-y)
      + min(x-1, n-y);
}

int SolveRook(int n, int x, int y) {
    return 2 * n - 2;
}

int SolveQueen(int n, int x, int y) {
    return SolveBishop(n, x, y) + SolveRook(n, x, y);
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    cout
        << "King: " << SolveKing(n, x, y) << endl
        << "Knight: " << SolveKnight(n, x, y) << endl
        << "Bishop: " << SolveBishop(n, x, y) << endl
        << "Rook: " << SolveRook(n, x, y) << endl
        << "Queen: " << SolveQueen(n, x, y) << endl;
    return 0;
}
