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

int main() {
    long long n, m;
    cin >> n >> m;

    n *= 3;
    long long sum = 0;
    int times = 0;
    for (int i = 0; i < m; ++i) {
        long long tmp;
        cin >> tmp;
        sum += tmp;
        ++times;
        if (sum > n)
            break;
    }

    if (sum > n) {
        cout << "Free after " << times << " times." << endl;
    } else {
        cout << "Team.GOV!" << endl;
    }

    return 0;
}
