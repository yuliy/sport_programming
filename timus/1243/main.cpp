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
    char buf[100];
    scanf("%s", buf);

    const int len = strlen(buf);
    int rem = 0;
    for (int i = 0; i < len; ++i) {
        const int num = rem * 10 + (buf[i] - '0');
        rem = num % 7;
        //cout << rem << endl;
    }

    printf("%d\n", rem);

    return 0;
}
