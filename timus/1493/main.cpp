#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

static bool Check(int num) {
    int s1 = 0;
    int s2 = 0;

    for (int i = 0; i < 3; ++i) {
        s1 += (num % 10);
        num /= 10;
    }
    for (int i = 0; i < 3; ++i) {
        s2 += (num % 10);
        num /= 10;
    }

    return (s1 == s2);
}

int main() {
    int n;
    cin >> n;

    if (Check(n-1) || Check(n+1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
