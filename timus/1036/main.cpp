#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

class TLongNum {
private:
    static const int LNUM_SIZE = 30;
    static const long long BASE = 10 * 1000 * 1000;
    long long arr[LNUM_SIZE];
public:
    TLongNum() {
        Init();
    }

    TLongNum(const TLongNum &other) {
        for (int i = 0; i < LNUM_SIZE; ++i)
            arr[i] = other.arr[i];
    }

    void Init() {
        for (int i = 0; i < LNUM_SIZE; ++i)
            arr[i] = 0;
    }

    TLongNum &operator += (const TLongNum &other) {
        long long carry = 0;
        for (int i = 0; i < LNUM_SIZE; ++i) {
            arr[i] += (other.arr[i] + carry);
            carry = arr[i] / BASE;
            arr[i] %= BASE;
        }
        return *this;
    }

    TLongNum &operator += (int num) {
        long long carry = num;
        for (int i = 0; i < LNUM_SIZE && carry; ++i) {
            arr[i] += carry;
            carry = arr[i] / BASE;
            arr[i] %= BASE;
        }
        return *this;
    }

    TLongNum &operator *= (const TLongNum &other) {
        long long carry = 0;
        for (int i = 0; i < LNUM_SIZE; ++i) {
            arr[i] = (arr[i] * other.arr[i] + carry);
            carry = arr[i] / BASE;
            arr[i] %= BASE;
        }
        return *this;
    }

    void Print() const {
        int start = 0;
        for (int i = LNUM_SIZE-1; i >= 0; --i)
            if (arr[i] != 0) {
                start = i;
                break;
            }
        //for (int i = LNUM_SIZE-1; i >= 0; --i)
        //    printf("%lld\n", arr[i]);
        //return;
        for (int i = start; i >= 0; --i) {
            if (i == start)
                printf("%lld", arr[i]);
            else
                printf("%07lld", arr[i]);
        }
    }
};

int N;
int S;
TLongNum a[52][1002];

static void Init() {
    //for (int i = 0; i <= 50; ++i)
    //    a[i][0] += 1;
    for (int j = 0; j < 10; ++j)
        a[1][j] += 1;
}

int main() {
    scanf("%d %d", &N, &S);
    Init();

    if (S % 2 == 1) {
        printf("0\n");
        return 0;
    }
    S /= 2;

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= S; ++j) {
            for (int d = 0; (d < 10) && (j >= d); ++d) {
                a[i][j] += a[i-1][j-d];
            }
        }
    }

    /*
    TLongNum res;
    for (int s = 1; s < S; ++s) {
        TLongNum t;
        t += a[N][s];
        t *= a[N][S-s];
        res += t;
        //res += (a[N][s] * a[N][S-s]);
    }
    */
    TLongNum res = a[N][S];
    res *= res;
    res.Print();
    printf("\n");
    return 0;
}
