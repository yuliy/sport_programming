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
    vector<string> v;
    char buf[32];
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        v.push_back(buf);
    }

    int res = 1;
    set<string> langs;
    string curLang = v[0];
    langs.insert(curLang);
    int gap = 0;
    for (int i = 1; i < n; ++i) {
        const string &s = v[i];
        if (s == "unknown") {
            ++gap;
        } else if (s == curLang) {
            gap = 0;
        } else {
            set<string>::const_iterator iter = langs.find(s);
            if (iter != langs.end()) {
                printf("Igor is wrong.\n");
                return 0;
            }

            //++res;
            res += gap;
            gap = 0;
            langs.insert(s);
        }
    }

    res += gap;
    for (int i = langs.size(); i <= res; ++i)
        printf("%d ", i);
    printf("\n");
    return 0;
}
