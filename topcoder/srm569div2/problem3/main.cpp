#include <iostream>
#include <vector>

using namespace std;

class MegaFactorialDiv2 {
public:
    int countDivisors(int N, int K) {
        long long a[1001][101];
        for (int k = 0; k <= K; ++k)
            a[0][k] = 1;
        for (int n = 0; n <= N; ++n)
            a[n][0] = n;

        for (int n = 1; n <= N; ++n) {
            for (int k = 1; k <= K; ++k) {
                a[n][k] = (a[n][k-1] * a[n-1][k]) % 1000000009;
            }
        }

        return a[N][K];
    }
};
