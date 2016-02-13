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
    int n, k;
    scanf("%d %d", &n, &k);

    int booms = 0;
    int droids = 0;
    for (int i = 0; i < n; ++i) {
        int ai;
        scanf("%d", &ai);
        const int d = abs(k - ai);
        if (ai > k) {
            booms += d;
        } else {
            droids += d;
        }
    }

    cout << booms << ' ' << droids << endl;
    return 0;
}
