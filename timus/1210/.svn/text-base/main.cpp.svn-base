#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

const int SIZE = 32;
const int MAX_PRICE = 1e9;

int main() {
    int N;
    scanf("%d", &N);
    
    int p[SIZE];
    int n[SIZE];
    for (int i = 0; i < SIZE; ++i)
        p[i] = MAX_PRICE;
    p[1] = 0;

    int pcnt = 0;
    for (int i = 0; i < N; ++i) {
        int ncnt;
        scanf("%d", &ncnt);

        for (int j = 0; j < SIZE; ++j)
            n[j] = MAX_PRICE;

        for (int k = 1; k <= ncnt; ++k) {
            for (;;) {
                int planetNum;
                scanf("%d", &planetNum);
                if (!planetNum)
                    break;

                int price;
                scanf("%d", &price);

                //cout << planetNum << "\t" << price << endl;
                const int nprice = p[planetNum] + price;
                if (nprice < n[k])
                    n[k] = nprice;
            }
            //cout << endl;
        }
        //cout << "---" << endl;
        
        char buf[8];
        scanf("%s", buf);

        for (int i = 0; i < SIZE; ++i)
            p[i] = n[i];
    }

    int res = MAX_PRICE;
    for (int i = 0; i < SIZE; ++i)
        if (n[i] < res)
            res = n[i];
    printf("%d\n", res);
    return 0;
}
