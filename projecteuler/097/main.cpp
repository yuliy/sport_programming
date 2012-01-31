#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    long long res = 1;
    const long long LD = 10000000000LL;
    for (long long i = 0; i < 7830457; ++i) {
        res *= 2;
        res %= LD;
    }

    res *= 28433;
    res %= LD;

    res += 1;
    res %= LD;

    cout << "Result = " << res << endl;

    return 0;
}
