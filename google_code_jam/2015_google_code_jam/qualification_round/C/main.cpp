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

typedef map<int, int> TMap;

static const bool DBG = false;

struct TQuat {
    static const int E = 0;
    static const int I = 1;
    static const int J = 2;
    static const int K = 3;

    bool Minus;
    int Value;

    TQuat() : Minus(false), Value(E) {}
    TQuat(bool minus, int val) : Minus(minus), Value(val) {}
};

TQuat Product(int a, int b) {
    switch (a.Value) {
        case TQuat::E: {
            case TQuat::E: return TQuat(false, TQuat::E);
            case TQuat::I: return TQuat(false, TQuat::I);
            case TQuat::J: return TQuat(false, TQuat::J);
            case TQuat::K: return TQuat(false, TQuat::K);
        } break;
        case TQuat::I: {
            case TQuat::E: return TQuat(false, TQuat::I);
            case TQuat::I: return TQuat(true,  TQuat::E);
            case TQuat::J: return TQuat(false, TQuat::K);
            case TQuat::K: return TQuat(true,  TQuat::J);
        } break;
        case TQuat::J {
            case TQuat::E: return TQuat(false, TQuat::J);
            case TQuat::I: return TQuat(true,  TQuat::K);
            case TQuat::J: return TQuat(true,  TQuat::E);
            case TQuat::K: return TQuat(false, TQuat::I);
        } break;
        case TQuat::K {
            case TQuat::E: return TQuat(false, TQuat::K);
            case TQuat::I: return TQuat(false, TQuat::J);
            case TQuat::J: return TQuat(true,  TQuat::I);
            case TQuat::K: return TQuat(true,  TQuat::E);
        } break;
    }
}

TQuat Product(TQuat a, TQuat b) {
    TQuat res = Product(a.Value, b.Value);
    if ((a.Minus && !b.Minus) || (!a.Minus && b.Minus)) {
        res.Minus = !res.Minus;
    }
    return res;
}

static void ExtendString(string& s, int X) {
    string tmp = s;
    for (int i = 1; i < X; ++i) {
        s += tmp;
    }
}

static bool CanSplit(const string& s) {
    return false;
}

static string SolveSingleCase() {
    int L, X;
    scanf("%d %d", &L, &X);
    string s;
    cin >> s;
    ExtendString(s, X);
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