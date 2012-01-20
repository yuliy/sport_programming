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
    const long long max = sqrt(num) + 1;
    for (long long i = 2; i < max; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int cnt = 0;
    for (long long i = 2; ; ++i) {
        if (IsPrime(i)) {
            //++cnt;
            //cout << cnt << ":\t" << i << endl;
        }
    }
    return 0;
}
