#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> odd, even;
    for (int i = 0 ; i < N; ++i) {
        int elem;
        scanf("%d", &elem);
        if (i & 1) {
            odd.push_back(elem);
        } else {
            even.push_back(elem);
        }
    }

    std::sort(even.begin(), even.end());
    std::sort(odd.begin(), odd.end(), greater<int>());

    int oddPos = 0;
    int evenPos = 0;
    for (int i = 0; i < N; ++i) {
        if (i & 1) {
            printf("%d ", odd[oddPos++]);
        } else {
            printf("%d ", even[evenPos++]);
        }
    }
    printf("\n");

    return 0;
}
