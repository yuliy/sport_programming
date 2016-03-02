#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
#include <ctime>
using namespace std;

int main() {
    string s;
    //std::srand(std::time(0));
    for (int i = 0; i < 1000000; ++i) {
        const char ch = (rand() % 26) + 'a';
        s += ch;
    }
    cout << s << endl;
    return 0;
}
