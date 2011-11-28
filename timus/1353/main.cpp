#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

const int MAX_R = 9;
const int MAX_S = 81;
int a[MAX_R+1][MAX_S+1];

int main() {
    int S;
    scanf("%d", &S);

    for (int j = 0; j <= S; ++j) {
        if (j < 10)
            a[1][j] = 1;
        else
            a[1][j] = 0;
    }

    for (int i = 2; i <= 9; ++i) {
        for (int j = 0; j <= S; ++j) {
            int tmp = 0;
            for (int k = 0; k <= 9; ++k) {
                if (k == 0 && i == 9)
                    continue;

                const int p = j - k;
                if (p >= 0)
                    tmp += a[i-1][p];
            }

            a[i][j] = tmp;
        }
    }

    for (int i = 1; i <= 9; ++i) {
        if (i == 1) {
            for (int j = 0; j <= S; ++j)
                cout << j << "\t";
            cout << endl << "-----------------------------------------------------------------------------------------------------" << endl;
            cout << endl;
        }

        for (int j = 0; j <= S; ++j)
            cout << a[i][j] << "\t";
        cout << endl;
    }

    int res = a[9][S];
    if (S == 1)
        ++res;
    printf("%d\n", res);
    
    return 0;
}
