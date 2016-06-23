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

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i <= (N-1); ++i) {
        for (int j = 0; j <= (N-2); ++j) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                printf("%d %d\n", j+1, j+2);
            }
        }
    }

    return 0;
}
