#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

float A, B;

static void Solve(int k, int a, int &resa, int &resb, float &sum) {
    const int b = k - a;
    if (a < 0 || b < 0)
        return;

    const float curSum = A*a + B*b - (a*a + b*b);
    if (curSum > sum) {
        resa = a;
        resb = b;
        sum = curSum;
    } else if (abs(curSum - sum) < 1e-5) {
        if (a < resa) {
            resa = a;
            resb = b;
        } else if (a == resa && b < resb) {
            resb = b;
        }
    }
}

int main() {
    int  K;
    scanf("%f %f %d", &A, &B, &K);

    int resa = -1;
    int resb = -1;
    float sum = 0.0;

    for (int k = 0; k <= K; ++k) {
        const int a = (A - B + 2*k) / 4;
        if (a < 0) {
            Solve(k, 0, resa, resb, sum);
        } else if (a > k) {
            Solve(k, k, resa, resb, sum);
        }else {
            for (int i = -10; i <= 10; ++i) {
                Solve(k, a+i, resa, resb, sum);
                //Solve(k, a+1, resa, resb, sum);
            }
        }
    }

    if (sum < 0.0 || resa < 0 || resb < 0) {
        sum = 0.0;
        resa = 0;
        resb = 0;
    }

    printf("%.2f\n%d %d\n", sum, resa, resb);

    return 0;
}
