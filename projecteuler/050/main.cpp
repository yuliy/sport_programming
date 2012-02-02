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
    for (long long i = 1; i < 1000*1000; ++i) {
        if (IsPrime(i))
            Primes.push_back(i);
    }
}

static int CheckNum(long long num, size_t numIdx) {
    int res = 0;

    for (size_t i = 0; i < numIdx; ++i) {

        long long sum = 0;
        int curRes = 0;
        for (size_t j = i; j <= numIdx; ++j) {
            sum += Primes[j];
            curRes += 1;
            if (sum == num) {
                if (curRes > res)
                    res = curRes;
                break;
            }
            if (sum > num)
                break;
        }
    }

    return res;
}

int main() {
    Init();

    int res = 0;
    const size_t cnt = Primes.size();
    for (size_t i = 0; i < cnt; ++i) {
        if (i % 1000 == 0)
            cout << "i=" << i << "\tres=" << res << endl;
        const long long num = Primes[i];
        const int curRes = CheckNum(num, i);
        if (curRes > res)
            res = curRes;
    }

    cout << "Result: " << res << endl;
    return 0;
}
