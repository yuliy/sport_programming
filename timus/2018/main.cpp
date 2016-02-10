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
static const int MAX_N = 50000;
static const int MAX_SEQ = 300;
static ui64 A[MAX_N+1][MAX_SEQ+1];
static ui64 B[MAX_N+1][MAX_SEQ+1];

void PAdd(ui64& left, ui64 right) {
    ui64 res = left + right;
    left = res % MOD;
}

class TApplication {
public:
    void Run() {
        cin >> N >> MaxA >> MaxB;
        Init();

        for (int k = 1; k <= N; ++k) {
            RunDynamics(k);
        }

        ui64 res = 0;
        for (int i = 1; i <= MaxA; ++i) {
            PAdd(res, A[N][i]);
        }
        for (int i = 1; i <= MaxB; ++i) {
            PAdd(res, B[N][i]);
        }

        cout << res << endl;
        //PrintDynamics();
    }
private:
    int N = 0;
    int MaxA = 0;
    int MaxB = 0;
private:
    void RunDynamics(int k) {
        for (int i = 1; i <= MaxB; ++i) {
            PAdd( A[k][1], B[k-1][i] );
        }

        for (int i = 2; i <= MaxA; ++i) {
            A[k][i] = A[k-1][i-1];
        }

        for (int i = 1; i <= MaxA; ++i) {
            PAdd( B[k][1], A[k-1][i] );
        }

        for (int i = 2; i <= MaxB; ++i) {
            B[k][i] = B[k-1][i-1];
        }
    }

    void Init() {
        for (int k = 0; k <= MAX_N; ++k) {
            for (int i = 0; i <= MAX_SEQ; ++i) {
                A[k][i] = B[k][i] = 0;
            }
        }

        A[1][1] = 1;
        B[1][1] = 1;
    }

    void PrintDynamics() {
        cout << "A:" << endl;
        for (int k = 1; k <= N; ++k) {
            for (int i = 1; i <= MaxA; ++i) {
                cout << A[k][i] << ' ';
            }
            cout << endl;
        }
        cout << endl;

        cout << "B:" << endl;
        for (int k = 1; k <= N; ++k) {
            for (int i = 1; i <= MaxB; ++i) {
                cout << B[k][i] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
};


int main() {
    TApplication app;
    app.Run();
    return 0;
}
