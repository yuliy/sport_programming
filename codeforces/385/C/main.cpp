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
vector<int> A(1e7 + 1, 0);
vector<i64> F(1e7 + 1, 0);

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int xi;
        scanf("%d", &xi);
        ++A[xi];
    }

    vector<bool> sieve(1e7 + 1, true);
    for (size_t i = 2; i < sieve.size(); ++i) {
        if (sieve[i]) {
            for (size_t j = i; j < sieve.size(); j +=i) {
                sieve[j] = false;
                F[i] += A[j];
            }
        }
    }

    /*
    for (int i = 0; i < 20; ++i) {
        cout << i << '\t' << F[i] << '\t' << A[i] << endl;
    }
    */
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
        if (li > ri)
            li = ri;

        const i64 res = F[ri] - F[li-1];
        printf("%Ld\n", res);
    }
    return 0;
}
