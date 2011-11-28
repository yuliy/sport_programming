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
    cin >> N;

    int num;
    scanf("%d", &num);
    int prev = num;
    int cnt = 1;
    for (int i = 1; i < N; ++i) {
        scanf("%d", &num);
        if (num == prev) {
            ++cnt;
        } else {
            printf("%d %d ", cnt, prev);
            prev = num;
            cnt = 1;
        }
    }
    printf("%d %d ", cnt, prev);

    return 0;
}
