#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

static char buf[200100];

static void RemovePairs() {

    char *rp = buf;
    char *p = buf;
    for (; *p; ++p, ++rp) {
        //cout << (p-buf) << endl << (rp-buf) << endl << "buf=" << buf << endl << endl;
        *rp = *p;
        while (rp > buf && *rp == *(rp-1))
            rp -= 2;
    }

    *rp = 0;
}

int main() {
    scanf("%s", buf);
    RemovePairs();
    printf("%s\n", buf);
    return 0;
}
