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

static bool IsPrime(long long num) {
    if (num == 2 || num == 3)
        return true;

    const long long max = sqrt(num) + 1;
    for (long long i = 2; i <= max; ++i) {
        if (num % i == 0)
            return false;
    }

    return true;
}

vector<long long> Primes;

static void Init() {
    for (long long i = 2; i < 1000*1000; ++i) {
        if (IsPrime(i))
            Primes.push_back(i);
    }
}

static int CalcDivisors(long long num) {
    int res = 0;
    for (vector<long long>::const_iterator iter = Primes.begin(), end = Primes.end(); iter != end; ++iter) {
        const long long p = *iter;
        bool flag = false;
        while (num && num % p == 0) {
            num /= p;
            flag = true;
        }
        if (flag)
            ++res;
        if (num == 1)
            break;
    }
    return res;
}

int main() {
    Init();

    for (long long i = 644; i < 1000*1000; ++i) {
        if (i % 10000 == 0)
            cout << "\ti=" << i << endl;
        if (CalcDivisors(i) == 4 &&
            CalcDivisors(i+1) == 4 &&
            CalcDivisors(i+2) == 4 &&
            CalcDivisors(i+3) == 4) {
            cout << "Result=" << i << endl;
            break;
        }
    }

    return 0;
}
