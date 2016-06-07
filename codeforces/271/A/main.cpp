#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

static bool IsMagic(int num) {
    bool digits[10] = {false};
    while (num) {
        const int d = num % 10;
        num /= 10;
        if (digits[d])
            return false;
        digits[d] = true;
    }
    return true;
}

int main() {
    int num;
    cin >> num;
    for (int i = num + 1; i <= 10000; ++i) {
        if (IsMagic(i)) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
