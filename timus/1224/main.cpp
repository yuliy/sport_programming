#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
using namespace std;

using ui64 = unsigned long long;

int main() {
    ui64 N, M;
    cin >> N >> M;

    const ui64 res = (N > M)
        ? (2 * M - 1)
        : (2 * N - 2);

    cout << res << endl;
    return 0;
}
