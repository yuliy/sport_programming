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

long long CalcKey(long long num) {
    vector<long long> d;
    while(num) {
        d.push_back(num % 10);
        num /= 10;
    }

    sort(d.begin(), d.end());

    const long long res = 1000 * d[0] + 100 * d[1] + 10 * d[2] + d[3];
    return res;
}

vector<long long> Primes;
typedef map<long long, vector<long long> > TKey2Nums;
TKey2Nums Key2Nums;

static void Init() {
    for (long long i = 1000; i < 10000; ++i) {
        if (IsPrime(i)) {
            Primes.push_back(i);
            Key2Nums[CalcKey(i)].push_back(i);
        }
    }

    /*
    for (TKey2Nums::const_iterator iter = Key2Nums.begin(), end = Key2Nums.end(); iter != end; ++iter) {
        if (iter->second.size() < 3)
            continue;

        cout << iter->first << endl;
        const vector<long long> &nums = iter->second;
        for (vector<long long>::const_iterator niter = nums.begin(), nend = nums.end(); niter != nend; ++niter) {
            cout << "\t" << *niter;
        }
        cout << endl;
    }
    */
}

int main() {
    Init();

    for (TKey2Nums::const_iterator iter = Key2Nums.begin(), end = Key2Nums.end(); iter != end; ++iter) {
        if (iter->second.size() < 3)
            continue;

        //cout << iter->first << endl;
        const vector<long long> &nums = iter->second;
        const int cnt = nums.size();
        for (int i = 0; i < (cnt-2); ++i) {
            for (int j = i+1; j < (cnt-1); ++j) {
                for (int k = j+1; k < cnt; ++k) {
                    const long long d1 = nums[j] - nums[i];
                    const long long d2 = nums[k] - nums[j];

                    if (d1 == d2)
                        cout << nums[i] << nums[j] << nums[k] << endl;
                }
            }
        }

    }
    return 0;
}
