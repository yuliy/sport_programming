#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int CountLuckyDigits(long long num) {
    int res = 0;
    while (num) {
        const int digit = num % 10;
        num /= 10;

        if (digit == 4 || digit == 7)
            ++res;
    }
    return res;
}

bool IsLucky(long long num) {
    if (!num)
        return false;

    while (num) {
        const int digit = num % 10;
        num /= 10;
        if (digit != 4 && digit != 7)
            return false;
    }
    return true;
}

int main() {
    long long num;
    cin >> num;

    if (IsLucky(CountLuckyDigits(num)))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
