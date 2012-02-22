#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

const char *s[] = {
    "0",
    "0",
    "2",
    "12",
    "60",
    "320",
    "1950",
    "13692",
    "109592",
    "986400",
    "9864090",
    "108505100",
    "1302061332",
    "16926797472",
    "236975164790",
    "3554627472060",
    "56874039553200",
    "966858672404672",
    "17403456103284402",
    "330665665962403980",
    "6613313319248079980",
    "138879579704209680000"
};

int main() {
    int N;
    cin >> N;
    cout << s[N] << endl;
    return 0;
}
