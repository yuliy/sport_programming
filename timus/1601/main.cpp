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
    char buf[10100];
    bool endSymMet = true;
    for (;gets(buf);) {
        for (char *p = buf; *p; ++p) {
            char &ch = *p;
            if ('A' <= ch && ch <= 'Z') {
                if (endSymMet)
                    endSymMet = false;
                else
                    ch += 32;
            }
            if (ch == '!' || ch == '.' || ch == '?')
                endSymMet = true;
        }

        printf("%s\n", buf);
    }
    return 0;
}
