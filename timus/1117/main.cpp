#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int S[40];

static void InitS() {
    S[3] = 2;
    for (int k = 4; k < 32; ++k)
        S[k] = (S[k-1] + k - 2) << 1;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    return 0;
}
