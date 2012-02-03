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

int main() {
    Init();

    int maxCnt = 0;
    int res = 0;

    const int cnt = Primes.size();
    for (int i = 0; i < cnt; ++i) {
        if (i % 1000 == 0)
            cout << "Primes[i]=" << Primes[i] << "\tres=" << res << "\tmaxCnt=" << maxCnt << endl;

        for (int k = 0; k < i; ++k) {
            long long num = 0;
            int c = 0;
            for (int j = k; j < i; ++j) {
                num += Primes[j];

                if (num == Primes[i]) {
                    c = j-k+1;
                    break;
                }
                
                if (num > Primes[i])
                    break;
            }

            if (c > maxCnt) {
                maxCnt = c;
                res = num;
            }
        }
    }

    cout << "Result: " << res << "\tmaxCnt=" << maxCnt << endl;
    return 0;
}
