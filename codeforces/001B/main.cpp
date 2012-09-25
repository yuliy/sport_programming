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

inline bool IsDigit(char ch) {
    return ('0' <= ch) && (ch <= '9');
}

bool HasExcelFormat(const char *s) {
    bool prevIsDigit = IsDigit(*s);
    ++s;

    for (; *s; ++s) {
        const bool curIsDigit = IsDigit(*s);
        if (prevIsDigit && !curIsDigit)
            return false;

        prevIsDigit = curIsDigit;
    }

    return true;
}

void Excel2Normal(const char *s, char *res) {
}

void Normal2Excel(const char *s, char *res) {
    char srow[10];
    char scol[10];

    ++s;
    int i = 0;
    for (i = 0; IsDigit(*s); ++s, ++i)
        srow[i] = *s;
    srow[i] = 0;

    ++s;
    for (i = 0; *s; ++s, ++i)
        scol[i] = *s;
    scol[i] = 0;

    int col;
    sscanf(scol, "%d", &col);
    vector<int> digits;
    while (col) {
        digits.push_back(col % 32);
        col /= 32;
    }

    for (vector<int>::const_reverse_iterator iter = digits.rbegin(), end = digits.rend(); iter != end; ++iter, ++res)
        //*res = (*iter + 'A');
        cout << "digit=" << *iter << endl;

    strcpy(res, srow);
}

int main() {
    int n;
    scanf("%d", &n);

    char buf[128];
    char res[128];
    for (int i = 0; i < n; ++i) {
        *res = 0;
        scanf("%s", buf);
        if (HasExcelFormat(buf))
            Excel2Normal(buf, res);
        else
            Normal2Excel(buf, res);

        printf("%s\n", res);
    }

    return 0;
}
