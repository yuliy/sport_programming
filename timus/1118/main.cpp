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

using i64 = long long;

class TApplication {
public:
    void Run() {
        int I, J;
        cin >> I >> J;
        cout << Solve(I, J) << endl;
    }
private:
    int Solve(int I, int J) {
        if ((I == 1) || (I == J))
            return I;

        InitSieve(J);

        int resN = I;
        int resSum = Sieve[I] + 1;

        for (int curN = I; curN <= J; ++curN) {
            const int curSum = Sieve[curN] + 1;
            if (((i64)resSum * curN) >= ((i64)curSum * resN)) {
                resN = curN;
                resSum = curSum;
            }
        }

        return resN;
    }

    void InitSieve(int N) {
        Sieve = vector<int>(N + 1);
        for (int div = 2; div <= N; ++div) {
            for (int i = div + div; i <= N; i += div) {
                Sieve[i] += div;
            }
        }
    }
private:
    vector<int> Sieve;
};

int main() {
    TApplication app;
    app.Run();
    return 0;
}
