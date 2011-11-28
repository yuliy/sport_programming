#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

static int Calc(char ch) {
    if ('a' <= ch && ch <= 'z')
        return ((ch-'a') % 3) + 1;
    switch(ch) {
    case '.': return 1;
    case ',': return 2;
    case '!': return 3;
    case ' ': return 1;
    }
    return 0;
}

int main() {
    string s;
    getline(cin, s);

    int res = 0;
    for (string::const_iterator iter = s.begin(), end = s.end(); iter != end; ++iter)
        res += Calc(*iter);
        //cout << *iter << "\t" << Calc(*iter) << endl;
    cout << res << endl;

    return 0;
}
