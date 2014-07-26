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

int main() {
    int n, m;
    cin >> n >> m;
    if (min(n, m) % 2)
        cout << "Akshat" << endl;
    else
        cout << "Malvika" << endl;
    return 0;
}
