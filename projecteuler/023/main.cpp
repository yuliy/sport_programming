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

enum NumType {
    NT_DEFICIENT = 0,
    NT_PERFECT = 1,
    NT_ABUNDANT = 2,
};

static NumType SpecifyNumType(int num) {
    int res = 1;
    const int max = num / 2;
    for (int i = 2; i <= max; ++i) {
        if (num == 1 || num < i)
            break;
        if (num % i == 0)
            res += i;
    }
    if (res < num)
        return NT_DEFICIENT;
    if (res == num)
        return NT_PERFECT;
    return NT_ABUNDANT;
}

const int MAX_NUM = 28123;
NumType NumTypeOf[MAX_NUM+2]; 

static void Init() {
    cout << "Calculating precompute..." << endl;
    for (int i = 1; i <= MAX_NUM; ++i) {
        NumTypeOf[i] = SpecifyNumType(i);
    }
    cout << "\tcompleted." << endl;
}

static bool NumCanBeWrittenAsSumOf2AbundantNums(int num) {
    for (int i = 1; i < (num-1); ++i) {
        if (NumTypeOf[i] == NT_ABUNDANT && NumTypeOf[num-i] == NT_ABUNDANT)
            return true;
    }
    return false;
}

int main() {
    Init();

    long long res = 0;
    for (int i = 1; i <= MAX_NUM; ++i) {
        if (i % 1000 == 0)
            cout << i << endl;
        if (!NumCanBeWrittenAsSumOf2AbundantNums(i))
            res += i;
    }
    cout << "Result: " << res << endl;

    return 0;
}
