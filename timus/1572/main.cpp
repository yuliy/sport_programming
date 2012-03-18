#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <math.h>
using namespace std;

const int CIRCLE = 1;
const int SQUARE = 2;
const int TRIANGLE = 3;

const double PI = 3.14159265;

int main() {
    int wType, wSz;
    scanf("%d %d", &wType, &wSz);

    double wSize = wSz;
    switch(wType) {
        case CIRCLE: {
            wSize *= 2;
        } break;
        case SQUARE: {
            wSize *= sqrt(2.0);
        } break;
        case TRIANGLE: {
            //
        } break;
    }

    int N;
    scanf("%d", &N);

    int res = 0;
    for (int i = 0; i < N; ++i) {
        int kType, kSize;
        scanf("%d %d", &kType, &kSize);
        double t = kSize;
        switch(kType) {
            case CIRCLE: {
                t *= 2;
            } break;
            case SQUARE: {
                //
            } break;
            case TRIANGLE: {
                t *= cos(30.0 / 180 * PI);
            } break;
        }
        //cout << wSize << "\t" << t << endl;
        if (t <= wSize)
            ++res;
    }

    printf("%d\n", res);
    return 0;
}
