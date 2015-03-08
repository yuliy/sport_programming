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

int main() {
    char buf1[10];
    char buf2[10];
    scanf("%s %s", buf1, buf2);

    int x0 = buf1[0] - 'a';
    int y0 = buf1[1] - '1';
    const int x1 = buf2[0] - 'a';
    const int y1 = buf2[1] - '1';

    vector<string> path;
    int res = 0;
    for (; x0 != x1 || y0 != y1; ++res) {
        string step;
        if (x0 < x1) {
            step.push_back('R');
            ++x0;
        } else if (x0 > x1) {
            step.push_back('L');
            --x0;
        }

        if (y0 < y1) {
            step.push_back('U');
            ++y0;
        } else if (y0 > y1) {
            step.push_back('D');
            --y0;
        }

        path.push_back(step);
    }

    printf("%d\n", res);
    for (vector<string>::const_iterator iter = path.begin(); iter != path.end(); ++iter)
        cout << *iter << endl;
    return 0;
}
