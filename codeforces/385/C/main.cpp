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

using i64 = long long;

int N;
vector<int> X;
vector<int> A(1e7 + 1);
vector<int> F(1e7 + 1);

int main() {
    scanf("%d", &N);
    X = vector<int>(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &X[i]);
        ++A[ X[i] ];
    }

    vector<bool> sieve(1e7 + 1, true);
    for (size_t i = 2; i < sieve.size(); ++i) {
        if (sieve[i]) {
            ++F[i];
            for (size_t j = i * i; j < sieve.size(); j +=i) {
                if (j > 1e7)
                    break;

                sieve[j] = false;
                F[j] += A[j];
            }
        }
    }

    for (int i = 1; i <= 1e7; ++i) {
        F[i] += F[i-1];
    }

    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int li, ri;
        scanf("%d %d", &li, &ri);
        if (ri > 1e7)
            ri = 1e7;

        const int res = F[ri] - F[li-1];
        printf("%d\n", res);
    }
    return 0;
}
