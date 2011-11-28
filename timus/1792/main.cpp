#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int a[7];

void Flip(int &num) {
    if (num == 0)
        num = 1;
    else
        num = 0;
}

static void Init() {
    for (int i = 0; i < 7; ++i)
        cin >> a[i];
}

static void Print() {
    for (int i = 0; i < 7; ++i)
        cout << a[i] << " ";
    cout << endl;
}

static bool Check() {
    const int t1 = (a[1] + a[2] + a[3]) % 2;
    const int t2 = (a[0] + a[2] + a[3]) % 2;
    const int t3 = (a[0] + a[1] + a[3]) % 2;
    return (t1 == a[4] && t2 == a[5] && t3 == a[6]);
}

int main() {
    Init();

    if (Check()) {
        Print();
        return 0;
    }

    for (int i = 0; i < 7; ++i) {
        Flip(a[i]);
        if (Check()) {
            Print();
            break;
        }
        Flip(a[i]);
    }

    return 0;
}
