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

using ui32 = unsigned int;

struct TNum {
    int Arr[32] = {0};

    void Add(ui32 num) {
        for (int i = 0; i < 32; ++i) {
            if (num & (1 << i)) {
                ++Arr[i];
            }
        }
    }

    void Remove(ui32 num) {
        for (int i = 0; i < 32; ++i) {
            if ((num & (1 << i)) && (Arr[i] > 0)) {
                --Arr[i];
            }
        }
    }

    ui32 Convert() const {
        ui32 res = 0;
        for (int i = 0; i < 32; ++i) {
            if (Arr[i] > 0) {
                res |= (1 << i);
            }
        }
        return res;
    }
};

int main() {
    int N;
    cin >> N;

    vector<ui32> a(N);
    for (int i = 0; i< N; ++i) {
        cin >> a[i];
    }

    vector<ui32> b(N);
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
    }

    ui32 res = 0;
    for (int l = 0; l < N; ++l) {
        TNum aNum;
        TNum bNum;
        aNum.Add(a[l]);
        bNum.Add(b[l]);
        res = max(res, aNum.Convert() + bNum.Convert());
        for (int r = l + 1; r < N; ++r) {
            aNum.Add(a[r]);
            bNum.Add(b[r]);
            res = max(res, aNum.Convert() + bNum.Convert());
        }
    }

    cout << res << endl;

    return 0;
}
