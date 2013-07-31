#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

typedef unsigned int ui32;
typedef long long i64;
typedef unsigned long long ui64;

const size_t MAX_N = 5001;
const ui64 MOD = 1e9 + 7;

int n, t;
int k, x;
int c[MAX_N+1];

ui64 fact[MAX_N + 1];
ui64 inv_fact[MAX_N + 1];

static ui64 Pow(ui64 a, ui32 p) {
    ui64 res = 1;
    for (; p; p >>= 1) {
        if (p & 1) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
    }
    return res;
}

static void Init() {
    fact[0] = 1;
    inv_fact[0] = 1;
    for (size_t i = 1; i <= MAX_N; ++i) {
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
        inv_fact[i] = Pow(fact[i], MOD-2);
    }
}

static ui64 Comb(ui32 n, ui32 k) {
    if (n < k || k < 0)
        return 0;
    return (((fact[n] * inv_fact[k]) % MOD) * inv_fact[n-k]) % MOD;
}

int main() {
    scanf("%d\t%d", &n, &t);
    for (int i = 0; i < n; ++i)
        scanf("%d", &c[i]);
    scanf("%d\t%d", &k, &x);

    Init();

    int l = 0, g = 0, s = 0;
    const int ak = c[k-1];
    for (int i = 0; i < n; ++i) {
        if (c[i] < ak)
            ++l;
        else if (ak < c[i])
            ++g;
        else
            ++s;
    }

    ui64 res = 0;
    for (int sl = 0; sl < x; ++sl) {
        for (int sr = 0; sr <= (t-x); ++sr) {
            if ((sl+sr) >= s)
                break;

            ui64 curRes = Comb(s-1, sl+sr) * Comb(l, x-sl-1);
            curRes %= MOD;
            curRes *= Comb(g, t-x-sr);
            curRes %= MOD;

            res += curRes;
            res %= MOD;
        }
    }

    printf("%lld\n", res);

    return 0;
}
