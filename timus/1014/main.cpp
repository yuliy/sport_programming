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
    int N;
    cin >> N;

    if (N == 0) {
        cout << "10" << endl;
        return 0;
    }
    if (N == 1) {
        cout << "1" << endl;
        return 0;
    }

    vector<int> v(10);

    for (int i = 9; i >= 2; --i) {
        for (; N % i == 0;) {
            ++v[i];
            N /= i;
        }
    }

    if (N > 1) {
        cout << "-1";
    } else {
        for (int i = 2; i < 10; ++i) {
            const int cnt = v[i];
            for (int j = 0; j < cnt; ++j)
                cout << i;
        }
    }
    cout << endl;

    return 0;
}
