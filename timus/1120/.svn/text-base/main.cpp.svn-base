#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
    long long N;
    scanf("%lld", &N);

    for (long long p = 1e5; p > 0; --p) {
        const long long tmp = 2*N + p - p*p;
        const long long a = tmp / (2*p);
        if (a <= 0)
            continue;
        //cout << a << "\t" << p << endl;
        if ((2 * a * p) == tmp) {
            printf("%lld %lld\n", a, p);
            break;
        }
    }

    return 0;
}
