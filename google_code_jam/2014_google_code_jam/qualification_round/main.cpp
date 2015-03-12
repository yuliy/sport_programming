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

static string SolveSingleCase() {
    return to_string(-1);
}

int main() {
    int numberOfTests = 0;
    cin >> numberOfTests;

    for (int i = 1; i <= numberOfTests; ++i) {
        cout << "Case #" << i << ": " << SolveSingleCase() << endl;
    }

    return 0;
}
