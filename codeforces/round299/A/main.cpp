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

static string OnesToString(int ones) {
    switch(ones) {
    case 0: return "zero";
    case 1: return "one";
    case 2: return "two";
    case 3: return "three";
    case 4: return "four";
    case 5: return "five";
    case 6: return "six";
    case 7: return "seven";
    case 8: return "eight";
    case 9: return "nine";
    }
    throw string("OnesToString failed!");
}

static string DecsToString(int decs) {
    switch(decs) {
    case 2: return "twenty";
    case 3: return "thirty";
    case 4: return "forty";
    case 5: return "fifty";
    case 6: return "sixty";
    case 7: return "seventy";
    case 8: return "eighty";
    case 9: return "ninety";
    }
    throw string("DecsToString failed!");
}

static string NumToString(int num) {
    if (num < 10)
        return OnesToString(num);

    switch (num) {
    case 10: return "ten";
    case 11: return "eleven";
    case 12: return "twelve";
    case 13: return "thirteen";
    case 14: return "fourteen";
    case 15: return "fifteen";
    case 16: return "sixteen";
    case 17: return "seventeen";
    case 18: return "eighteen";
    case 19: return "nineteen";
    }

    const int decs = num / 10;
    const int ones = num % 10;

    if (ones != 0) {
        return DecsToString(decs) + "-" + OnesToString(ones);
    } else {
        return DecsToString(decs);
    }
}

int main() {
    try {
        int s;
        cin >> s;
        cout << NumToString(s) << endl;
    } catch (const std::string& s) {
        cout << "shit happend: " << s << endl;
        throw;
    }
    return 0;
}
