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
    const int cnt = (n >> 1) + (n % 2);
    if (cnt % 2)
        printf("grimy");
    else
        printf("black");
    return 0;
}
