#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    const int c1 = s1[3];
    const int c2 = s2[3];
    if (c1 % 2 == 0 || c2 % 2 != 0)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
