#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
using namespace std;

using ui64 = unsigned long long;

bool IsPrime(ui64 num) {
    const ui64 maxDiv = sqrt(num);
    for (ui64 div = 2; div <= maxDiv; ++div) {
        if (num % div == 0)
            return false;
    }
    return true;
}

int main() {
    /*
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;

    }
    */

    int p = 0;
    for (ui64 N = 2; N < 64; ++N) {
        const ui64 num = (1ULL << N) - 1;
        if (IsPrime(num)) {
            ++p;
            cout << p << '\t' << N << endl;
        }
    }

    return 0;
}
