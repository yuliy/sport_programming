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

const size_t MAX_N = 5000;
const ui64 MOD = 1e9 + 7;

int n, t;
int k, x;
int c[MAX_N+1];

ui64 fact[MAX_N + 1];
ui64 inv_fact[MAX_N + 1];

static ui64 Pow(ui64 num) {

}

static void Init() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
        fact[i] = fact[i-1] * i;
    }
}

int main() {
    scanf("%d\t%d", &n, &t);
    vector<int> c(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &c[i]);
    scanf("%d\t%d", &k, &x);

    Init();

    return 0;
}
