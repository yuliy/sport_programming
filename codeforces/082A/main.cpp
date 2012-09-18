#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

const char* names[] = {
    "Howard",
    "Sheldon",
    "Leonard",
    "Penny",
    "Rajesh",
    "Howard",
};

int main() {
    int N;
    scanf("%d", &N);

    int tmp = 5;
    int dup = 1;
    while (N > tmp) {
        N -= tmp;
        tmp *= 2;
        dup *= 2;
        //cout << "N=" << N << "\ttmp=" << tmp << "\tdup=" << dup << endl;
    }

    int num = N / dup;
    if (N % dup)
        ++num;
    //cout << "num=" << num << endl;
    printf("%s\n", names[num]);
    return 0;
}
