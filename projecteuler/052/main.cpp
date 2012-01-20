#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

typedef long long ui64;

void CalcDigits(ui64 num, int *digits) {
    for (int i = 0; i < 10; ++i)
        digits[i] = 0;

    while (num) {
        const int d = num % 10;
        ++digits[d];
        num /= 10;
    }
}

static bool CompareDigits(const int *ds1, const int *ds2) {
    for (int i = 0; i < 10; ++i)
        if (ds1[i] != ds2[i])
            return false;
    return true;
}

int main() {
    int ds1[10];
    int ds2[10];
    for (int num = 1; ; ++num) {
        if (num % 100 == 0)
            cout << "current num = " << num << endl;

        CalcDigits(num, ds1);
        bool flag = true;
        for (int i = 2; i <= 6; ++i) {
            CalcDigits(num * i, ds2);
            if (!CompareDigits(ds1, ds2)) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "Result: " << num << endl;
            break;
        }
    }
    return 0;
}
