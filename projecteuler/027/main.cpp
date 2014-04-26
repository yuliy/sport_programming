#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

class TPrimeChecker {
private:
    int MaxChecked;
    set<int> Primes;
private:
    bool IsPrimeEx(int num) {
        for (int divisor = floor(sqrt(num)); divisor < num; ++divisor) {
            if (0 == num % divisor)
                return false;
        }
        return true;
    }
public:
    TPrimeChecker()
        : MaxChecked(1)
    {}

    bool IsPrime(int num) {
        for (int i = MaxChecked + 1; i <= num; ++i) {
            if (IsPrimeEx(i))
                Primes.insert(i);
        }
        return Primes.find(num) != Primes.end();
    }
};

static TPrimeChecker PrimeChecker;

static const int MIN = -999;
static const int MAX = 999;

int calc_prime_seq_len(int a, int b) {
    int res = 0;
    for (int n = 0; PrimeChecker.IsPrime(n*n + a*n + b); ++n, ++res)
    {}
    return res;
}

int main() {
    int max = 0;
    for (int a = MIN; a <= MAX; ++a) {
        for (int b = MIN; b <= MAX; ++b) {
            const int len = calc_prime_seq_len(a, b);
            if (len > max) {
                max = len;
                cout << "a=" << a << " b=" << b << " len=" << len << endl;
            }
        }
    }
    return 0;
}
