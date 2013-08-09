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

typedef unsigned int ui32;

int N;
vector<ui32> a;

static void ReadInput() {
    scanf("%d", &N);

    set<ui32> dict;
    for (int i = 0; i < N; ++i) {
        ui32 tmp;
        scanf("%u", &tmp);
        if (dict.find(tmp) == dict.end()) {
            a.push_back(tmp);
            dict.insert(tmp);
        }
    }
}

int main() {
    ReadInput();
    //
    return 0;
}
