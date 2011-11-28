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
    int N;
    scanf("%d", &N);

    int a[60005];
    a[1] = 1;
    a[2] = 2;

    for (int n = 3; n <= N; ++n) {
        a[n] = a[n-1] + 1;
        for (int i = 2; i <= n; ++i) {
            const int q = i * i;
            if (q > n)
                break;
            if (q == n) {
                a[n] = 1;
                break;
            }

            const int curRes = a[n-i*i] + 1;
            if (curRes < a[n])
                a[n] = curRes;
        }
    }

    //for (int i = 0; i <= N; ++i)
    //    cout << i << ":\t" << a[i] << endl;

    printf("%d\n", a[N]);

    return 0;
}
