#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

void SolveSameInitialPositions(int n, const vector<int>& v, int sa, int sb) {
    int suma = 0;
    int sumb = 0;
    for (int i = 0; i < n; ++i) {
        if (i <= sa) {
            suma += v[i];
        } else {
            sumb += v[i];
        }
    }

    if (suma < sumb) {
        swap(suma, sumb);
        sumb -= v[sa];
        suma += v[sa];
    }

    cout << suma << "\t" << sumb << endl;
}

void SolveDifferentInitialPositions(int n, const vector<int>& v, int sa, int sb) {
    bool swapped = false;
    if (sa > sb) {
        swap(sa, sb);
        swapped = true;
    }

    const int dist = sb - sa - 1;
    if (dist % 2) {
        if (swapped) {
            sa += dist / 2;
        } else {
            sa += dist / 2 + 1;
        }
    } else {
        sa += dist / 2;
    }
    sb = sa + 1;

    int suma = 0;
    int sumb = 0;
    for (int i = 0; i < n; ++i) {
        if (i <= sa) {
            suma += v[i];
        } else {
            sumb += v[i];
        }
    }

    if (swapped)
        swap(suma, sumb);
    cout << suma << "\t" << sumb << endl;
}

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

    if (sa == sb) {
        SolveSameInitialPositions(n, v, sa, sb);
    } else {
        SolveDifferentInitialPositions(n, v, sa, sb);
    }

    return 0;
}
