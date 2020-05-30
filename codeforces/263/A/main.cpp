#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

void findIJ(int& i, int& j) {
    for (i = 0; i < 5; ++i) {
        for (j = 0; j < 5; ++j) {
            int tmp;
            cin >> tmp;
            if (tmp == 1) {
                return;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int i, j;
    findIJ(i, j);
    cout << (abs(i - 2) + abs(j - 2)) << endl;
    return 0;
}
