#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int n;

static bool Check(const vector<string> &v, int k, int p) {
    //cout << "=================================" << endl;
    //cout << "p=" << p << endl;
    set<string> langs;
    for (int l = 0; l < p; ++l) {
        //cout << "(1)" << endl;
        const int offset = l * k;
        int firstPhrase = -1;
        string lang;
        for (int i = 0; i < k; ++i) {
            lang = v[i + offset];
            if (lang != "unknown") {
                firstPhrase = i;
                break;
            }
        }

        //cout << "(2)" << endl;
        //cout << "lang=" << lang << endl;
        if (firstPhrase == -1)
            continue;

        set<string>::const_iterator liter = langs.find(lang);
        if (liter != langs.end())
            return false;

        langs.insert(lang);
        //cout << "(3)" << endl;

        for (int i = firstPhrase; i < k; ++i) {
            //cout << "(4)" << endl;
            //cout << v[i+offset] << endl;
            if (v[i+offset] == "unknown")
                continue;
            if (v[i+offset] != lang)
                return false;
        }
    }

    return true;
}

int main() {
    scanf("%d", &n);
    vector<string> v;
    char buf[32];
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        v.push_back(buf);
    }

    vector<int> res;
    for (int k = n; k > 0; --k) {
        if (n % k)
            continue;

        const int p = n / k;
        if (Check(v, k, p))
            res.push_back(p);
    }

    if (res.empty()) {
        printf("Igor is wrong.\n");
    } else {
        for (vector<int>::const_iterator iter = res.begin(); iter != res.end(); ++iter)
            printf("%d ", *iter);
        printf("\n");
    }
    return 0;
}
