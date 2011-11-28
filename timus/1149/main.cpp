#include <stdio.h>
#include <stdlib.h>
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
    scanf("%d", &N);

    vector<string> a;
    a.push_back("");

    char buf[32];
    for (int n = 1; n <= N; ++n) {
        string s;
        bool plus = false;
        for (int i = 1; i <= n; ++i) {
            s += "sin(";
            sprintf(buf, "%d", i);
            s += buf;
            if (i < n)
                s += (plus ? "+" : "-");
            plus = !plus;
        }

        for (int i = 1; i <= n; ++i)
            s += ")";

        a.push_back(s);
    }

    //for (vector<string>::const_iterator iter = a.begin(), end = a.end(); iter != end; ++iter)
    //    cout << *iter << endl;
    /*for (int i = 1; i < N; ++i) {
        sprintf(buf, "%d", i);
        a[i] = "A";
        a[i] += buf;
    }*/

    string res;
    for (int n = 1; n < N; ++n)
        res += "(";

    for (int n = 1; n <= N; ++n) {
        if (n != 1)
            res += ")";
        res += a[n];
        res += "+";
        sprintf(buf, "%d", N-n+1);
        res += buf;
    }

    cout << res << endl;

    return 0;
}
