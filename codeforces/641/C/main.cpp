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


enum EWheelType {
    ODD = 0,
    EVEN = 1
};

struct TWheel {
    EWheelType Type;
    int Pos = 0;
    int Size;

    TWheel(EWheelType type, int N)
        : Type(type)
        , Size(N/2)
    {}

    void RollBy(int p) {
        Pos -= p;
        while (Pos >= Size)
            Pos -= Size;
        while (Pos < 0)
            Pos += Size;
    }

    int GetValue() const {
        return (Type == ODD)
            ? (Pos * 2 + 1)
            : (Pos * 2 + 2);
    }
};

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    TWheel w0(ODD, N);
    TWheel w1(EVEN, N);

    for (int i = 0; i < Q; ++i) {
        char buf[5];
        scanf("%s", buf);
        const char command = buf[0];
        if (command == '1') {
            int x;
            scanf("%d", &x);
            if (x < 0)
                x += N;

            w0.RollBy(x/2);
            w1.RollBy(x/2);
            if (x & 1) {
                swap(w0, w1);
                w0.RollBy(1);
            }
        } else {
            swap(w0, w1);
        }
    }

    for (int i = 0; i < (N/2); ++i) {
        printf ("%d %d ", w0.GetValue(), w1.GetValue());
        w0.RollBy(-1);
        w1.RollBy(-1);
    }
    printf("\n");

    return 0;
}
