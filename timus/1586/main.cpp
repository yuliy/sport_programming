#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

static bool IsSimpleNum(int num) {
    const int max = sqrt((double)num);
    for (int i = 2; i <= (max+1); ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

static int Get3Prefix(int num) {
    num /= 10;
    int res = (num % 10);
    num /= 10;
    res += ((num % 10) * 10);
    return res;
}

static int GetPostfix(int num) {
    int res = (num % 10);
    num /= 10;
    res += ((num % 10) * 10);
    return res;
}

bool IsSimple[1000];

int NUM_2_PREFIX[1000];

typedef map<int, map<int, int> > TP2Ps2Cnt;
TP2Ps2Cnt p2ps2cnt;

long long a[100][10005];

static void Init() {
    // simple numbers
    for (int i = 0; i < 1000; ++i)
        IsSimple[i] = IsSimpleNum(i);

    // simple numbers prefixes
    for (int i = 0; i < 1000; ++i)
        NUM_2_PREFIX[i] = Get3Prefix(i);

    // p2ps2cnt
    for (int i = 100; i < 1000; ++i) {
        if (IsSimple[i]) {
            const int postfix = GetPostfix(i);
            for (int j = 100; j < 1000; ++j) {
                if (IsSimple[j]) {
                    const int prefix = Get3Prefix(j);
                    if (prefix == postfix) {
                        ++p2ps2cnt[postfix][GetPostfix(j)];
                        //++p2ps2cnt[i][j];
                    }
                }
            }
        }
    }

    /*
    for (TP2Ps2Cnt::const_iterator iter = p2ps2cnt.begin(), end = p2ps2cnt.end(); iter != end; ++iter) {
        cout << iter->first << ":";
        const map<int, int> &prefixes = iter->second;
        for (map<int, int>::const_iterator piter = prefixes.begin(), pend = prefixes.end(); piter != pend; ++piter) {
            cout << "\t" << piter->first << ":" << piter->second;
        }
        cout << endl;
    }
    */

    // a
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 10005; ++j)
            a[i][j] = 0;
}


int main() {
    Init();

    int N;
    scanf("%d", &N);

    for (int i = 100; i < 1000; ++i) {
        if (IsSimple[i]) {
            ++a[GetPostfix(i)][3];
        }
    }

    for (int n = 3; n < N; ++n) {
        for (int p = 10; p < 100; ++p) {
            if (a[p][n] == 0)
                continue;

            const map<int, int> &ps2cnt = p2ps2cnt[p];
            for (map<int, int>::const_iterator iter = ps2cnt.begin(), end = ps2cnt.end(); iter != end; ++iter) {
                long long &c = a[iter->first][n+1];
                c += iter->second;
                //c += (iter->second * a[p][n]);
                c %= 1000000009;
            }
        }
    }

    long long res = 0;
    for (int p = 0; p < 100; ++p) {
        res += a[p][N];
        res %= 1000000009;
    }
    printf("%lld\n", res);

    /*
    for (int n = 3; n <= N; ++n)
        cout << "\t" << n;
    for (int p = 0; p < 100; ++p) {
        cout << "p=" << p << "|\t";
        for (int n = 3; n <= N; ++n) {
            cout << a[p][n] << "\t";
        }
        cout << endl;
    }
    */

    return 0;
}
