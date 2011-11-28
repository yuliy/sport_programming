#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAX_ELEMS = 100;
const int BASE = 1e+1;

static void Multiply(int *num, int m) {
    int carry = 0;
    for (int i = 0; i < MAX_ELEMS; ++i) {
        int &tmp = num[i];
        tmp = tmp * m + carry;
        carry = tmp / BASE;
        tmp = tmp % BASE;
    }
}

static void PrintNum(int *num) {
    int firstNonNegativeIndex = 0;
    for (int i = MAX_ELEMS-1; i >= 0; --i) {
        if (num[i] != 0) {
            firstNonNegativeIndex = i;
            break;
        }
    }

    for (int i = firstNonNegativeIndex; i >= 0; --i) {
        printf("%d", num[i]);
    }
    printf("\n");
}

int main() {
    int K;
    scanf("%d", &K);

    int res[MAX_ELEMS];
    for (int i = 0; i < MAX_ELEMS; ++i)
        res[i] = 0;
    res[0] = 55 - 19;
    for (int i = 0; i < (K-1); ++i) {
        //PrintNum(res);
        Multiply(res, 55);
    }

    PrintNum(res);

    return 0;
}
