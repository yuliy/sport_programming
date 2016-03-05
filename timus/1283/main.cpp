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
#include <cmath>
using namespace std;

int main() {
    //n <= log[e](lim/sum) / log[e]((100-k)/100)
    double sum, lim, k;
    cin >> sum >> lim >> k;

    int res = 0;
    const double m = (100-k) / 100;
    while (sum > lim) {
        sum *= m;
        ++res;
    }
    cout << res << endl;
    //const double n = log(lim/sum) / log((100-k)/100);
    //cout << ceil(n) << endl;
    return 0;
}
