#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

const char WINDOW[] = "window";
const char AISLE[] = "aisle";
const char NEITHER[] = "neither";

int main() {
    char buf[32];
    scanf("%s", buf);
    
    const int len = strlen(buf);
    const char seat = buf[len-1];

    int row = buf[0] - '0';
    if (len == 3) {
        row *= 10;
        row += (buf[1] - '0');
    }

    if (row < 3) {
        if (seat == 'A' || seat == 'D')
            cout << WINDOW;
        else
            cout << AISLE;
    } else if (row < 21) {
        if (seat == 'A' || seat == 'F')
            cout << WINDOW;
        else if (seat == 'B' || seat == 'C' || seat == 'D' || seat == 'E')
            cout << AISLE;
    } else {
        if (seat == 'A' || seat == 'K')
            cout << WINDOW;
        else if (seat == 'C' || seat == 'D' || seat == 'H' || seat == 'J')
            cout << AISLE;
        else
            cout << NEITHER;
    }
    cout << endl;

    return 0;
}
