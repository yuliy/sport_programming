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
    //n <= log[e](lim/sum) / log[e](k/100)
    double sum, lim, k;
    cin >> sum >> lim >> k;
    const double n = log(lim/sum) / log(k/100);
    cout << floor(n) << endl;
    return 0;
}
