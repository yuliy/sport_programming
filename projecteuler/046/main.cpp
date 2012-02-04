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

static bool CheckIfCanBeWrittenAsASumOfPrimeAndTwiceASquare(long long num) {
    for (vector<long long>::const_iterator iter = Primes.begin(), end = Primes.end(); iter != end; ++iter) {
        const long long p = *iter;
        if (p > num)
            break;

        for (long long i = 1; ; ++i) {
            const long long sum = p + 2 * i * i;
            if (sum == num)
                return true;
            if (sum > num)
                break;
        }
    }
    return false;
}

int main() {
    Init();

    for (long long i = 5; i < 1000*1000; i+=2) {
        if (i % 1000 == 0)
            cout << "\ti=" << i << endl;
        if (!CheckIfCanBeWrittenAsASumOfPrimeAndTwiceASquare(i) && !IsPrime(i)) {
            cout << "Result=" << i << endl;
            break;
        }
    }

    return 0;
}
