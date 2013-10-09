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

typedef unsigned int ui32;
typedef int i32;

int N;
vector<ui32> a;
int MaxBeauty = -1;

/*
static int NumBeauty(ui32 num) {
    int res = 0;
    for ( ; 0 == (num & 1); num >>= 1, ++res);
    return res;
}
*/

static void ReadInput() {
    scanf("%d ", &N);
    for (int i = 0; i < N; ++i) {
        ui32 tmp;
        scanf("%u ", &tmp);
        a.push_back(tmp);
        //const int b = NumBeauty(tmp);
        //if (b > MaxBeauty)
        //    MaxBeauty = b;
    }
}

int main() {
    vector<ui32> res;
    for (int b = 0; b < 32; ++b) {
        vector<ui32> curRes;
        const ui32 bits = 0xFF;
        const ui32 mask = 1 << b;
        const ui32 mask2 = ~(0xFF << (b-1));
        for (int i = 0; i < N; ++i) {
            const ui32 num = a[i];
            if ((num & mask) == 0)
                continue;
            if ((num & mask))
                continue;
        }
    }
    /*
    ReadInput();
    vector<int> res;
    const ui32 mask = (1 << MaxBeauty);
    for (vector<ui32>::const_iterator iter = a.begin(); iter != a.end(); ++iter) {
        const ui32 num = *iter;
        const int b = NumBeauty(num);
        if (num & mask)
            res.push_back(num);
    }

    const int k = res.size();
    printf("%d\n", k);
    for (int i = 0; i < k; ++i)
        printf("%u ", res[i]);
    */

    return 0;
}
