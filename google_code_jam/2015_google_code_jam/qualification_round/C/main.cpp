#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

static const bool DBG = false;
static const int MAXSZ = 10001;

struct TQuat {
    static const int E = 0;
    static const int I = 1;
    static const int J = 2;
    static const int K = 3;

    bool Minus;
    int Value;

    TQuat() : Minus(false), Value(E) {}
    TQuat(bool minus, int val) : Minus(minus), Value(val) {}

    bool operator==(const TQuat& other) const {
        return (Minus == other.Minus) && (Value == other.Value);
    }
};

static TQuat Product(int a, int b) {
    switch (a) {
    case TQuat::E: {
        switch (b) {
        case TQuat::E: return TQuat(false, TQuat::E);
        case TQuat::I: return TQuat(false, TQuat::I);
        case TQuat::J: return TQuat(false, TQuat::J);
        case TQuat::K: return TQuat(false, TQuat::K);
        }
    } break;
    case TQuat::I: {
        switch (b) {
        case TQuat::E: return TQuat(false, TQuat::I);
        case TQuat::I: return TQuat(true,  TQuat::E);
        case TQuat::J: return TQuat(false, TQuat::K);
        case TQuat::K: return TQuat(true,  TQuat::J);
        }
    } break;
    case TQuat::J: {
        switch (b) {
        case TQuat::E: return TQuat(false, TQuat::J);
        case TQuat::I: return TQuat(true,  TQuat::K);
        case TQuat::J: return TQuat(true,  TQuat::E);
        case TQuat::K: return TQuat(false, TQuat::I);
        }
    } break;
    case TQuat::K: {
        switch (b) {
        case TQuat::E: return TQuat(false, TQuat::K);
        case TQuat::I: return TQuat(false, TQuat::J);
        case TQuat::J: return TQuat(true,  TQuat::I);
        case TQuat::K: return TQuat(true,  TQuat::E);
        }
    } break;
    }
}

static TQuat Product(TQuat a, TQuat b) {
    TQuat res = Product(a.Value, b.Value);
    if ((a.Minus && !b.Minus) || (!a.Minus && b.Minus)) {
        res.Minus = !res.Minus;
    }
    return res;
}

TQuat Precomp[MAXSZ][MAXSZ];

static void CalcPrecomp(const string& s) {
    Precomp[0][0] = 1;
}

static void ExtendString(string& s, int X) {
    string tmp = s;
    for (int i = 1; i < X; ++i) {
        s += tmp;
    }
}

// Intervals:
//  [0; d1)
//  [d1; d2)
//  [d2; sz)
static bool CanSplit(const string& s, int d1, int d2, int sz) {
    const TQuat& v1 = Precomp[0][d1];
    const TQuat& v2 = Precomp[d1][d2];
    const TQuat& v3 = Precomp[d2][sz];
    return (v1 == TQuat(false, TQuat::I))
        && (v2 == TQuat(false, TQuat::J))
        && (v3 == TQuat(false, TQuat::K));
}

static bool CanSplit(const string& s) {
    const int sz = s.size();
    for (int d1 = 1; d1 < (sz-2); ++d1) {
        for (int d2 = d1 + 1; d2 < (sz-1); ++d2) {
            if (CanSplit(s, d1, d2, sz))
                return true;
        }
    }
    return false;
}

static string SolveSingleCase() {
    int L, X;
    scanf("%d %d", &L, &X);
    string s;
    cin >> s;
    ExtendString(s, X);
    CalcPrecomp(s);
    return CanSplit(s) ? "YES" : "NO";
}

int main() {
    int numberOfTests = 0;
    cin >> numberOfTests;

    for (int i = 1; i <= numberOfTests; ++i) {
        cout << "Case #" << i << ": " << SolveSingleCase() << endl;
    }

    return 0;
}
