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

using ui64 = unsigned long long;

static const ui64 MOD = 1e9 + 7;
void Add(ui64& left, ui64 right) {
    ui64 res = left + right;
    left = res % MOD;
}

class TApplication {
public:
    void Run() {
        Init();

        for (int k = 2; k <= N; ++k) {
            RunDynamics(k);
        }

        ui64 res = 0;
        for (int i = 1; i <= MaxA; ++i) {
            Add(res, A[i]);
        }
        for (int i = 1; i <= MaxB; ++i) {
            Add(res, B[i]);
        }

        cout << res << endl;
    }
private:
    int N = 0;
    int MaxA = 0;
    int MaxB = 0;
    static const int MAX_SEQ = 300;
    vector<ui64> A;
    vector<ui64> B;
private:
    void RunDynamics(int k) {
        vector<ui64> newA(MaxA + 1);
        vector<ui64> newB(MaxB + 1);

        for (int i = 1; i <= MaxB; ++i) {
            Add( newA[1], B[i] );
        }

        for (int i = 2; i <= MaxA; ++i) {
            newA[i] = A[i-1];
        }

        for (int i = 1; i <= MaxA; ++i) {
            Add( newB[1], A[i] );
        }

        for (int i = 2; i <= MaxB; ++i) {
            newB[i] = B[i-1];
        }

        A.swap(newA);
        B.swap(newB);
    }

    void Init() {
        cin >> N >> MaxA >> MaxB;

        A.resize(MaxA + 1);
        B.resize(MaxB + 1);

        A[1] = 1;
        B[1] = 1;
    }
};


int main() {
    TApplication app;
    app.Run();
    return 0;
}
