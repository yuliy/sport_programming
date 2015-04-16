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
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    int sa, sb;
    scanf("%d %d", &sa, &sb);
    --sa; --sb;
    bool swapped = false;
    if (sa > sb) {
        swap(sa, sb);
        swapped = true;
    }

    const int dist = sb - sa - 1;
    if (dist % 2) {
        sa += dist / 2 + 1;
    } else {
        sa += dist / 2;
    }
    sb = sa + 1;
    //cout << sa << " " << sb << endl;

    int suma = 0;
    int sumb = 0;
    for (int i = 0; i < n; ++i) {
        if (i <= sa) {
            suma += v[i];
        } else {
            sumb += v[i];
        }
    }

    if (swapped) {
        cout << sumb << "\t" << suma << endl;
    } else {
        cout << suma << "\t" << sumb << endl;
    }

    return 0;
}
