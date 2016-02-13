#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

string Solve(int row, char seat) {
    if (row <= 2) {
        if (strchr("AD", seat))
            return "window";
        return "aisle";
    } else if (row <= 20) {
        if (strchr("AF", seat))
            return "window";
        return "aisle";
    } else {
        if (strchr("AK", seat))
            return "window";
        if (strchr("CDGH", seat))
            return "aisle";
        return "neither";
    }
}

int main() {
    int row;
    char seat;
    scanf("%d%c", &row, &seat);
    cout << Solve(row, seat) << endl;
    return 0;
}
