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
    int n;
    scanf("%d", &n);


    int splitCount = 0;
    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        scanf("%d", &tmp);

        splitCount += (tmp / 2);
    }

    if (splitCount % 2) {
        cout << "Daenerys" << endl;
    } else {
        cout << "Stannis" << endl;
    }

    return 0;
}
