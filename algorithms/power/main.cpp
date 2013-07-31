#include <iostream>
using namespace std;

typedef unsigned int ui32;
typedef unsigned long long ui64;

/*
ui32 Pow(ui32 a, ui32 p) {
    ui32 res = 1;
    for (; p; p >>= 1, a *= a)
        if (p & 1)
            res *= a;
    return res;
}
*/

ui64 Pow(ui64 a, ui64 p) {
    ui64 res = 1;
    for (; p; p >>= 1, a *= a)
        if (p & 1)
            res *= a;
    return res;
}

int main() {
    cout << "Pow(2, 3) = " << Pow(2, 3) << endl;
    cout << "Pow(2, 30) = " << Pow(2, 30) << endl;
    return 0;
}
