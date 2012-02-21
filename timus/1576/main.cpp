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
    // base
    int N1, C1;
    scanf("%d %d", &N1, &C1);

    // combined
    int N2, T, C2;
    scanf("%d %d %d", &N2, &T, &C2);

    // unlim
    int N3;
    scanf("%d", &N3);

    int K;
    scanf("%d", &K);

    int time = 0;
    for (int i = 0; i < K; ++i) {
        int m, s;
        scanf("%d:%d", &m, &s);
        cout << m << "\t" << s << endl;

        if (m == 0 && s <= 6)
            continue;

        time += m;
        if (s > 0)
            ++time;
    }

    const int basic = N1 + time * C1;
    int combined = N2;
    if (time > T)
        combined += (C2 * (time-T));

    printf("Basic:     %d\n", basic);
    printf("Combined:  %d\n", combined);
    printf("Unlimited: %d\n", N3);

    return 0;
}
