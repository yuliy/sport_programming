#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N = 10000;

    vector<int> numbers;
    set<int> dict;
    for (int i = 1; i <= (N+1); ++i) {
        const int num = (i * (3 * i - 1)) >> 1;
        numbers.push_back(num);
        dict.insert(num);
    }

    int D = 1e9;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            const int sum = numbers[i] + numbers[j];
            const int diff = numbers[i] - numbers[j];
            if (dict.find(sum) == dict.end())
                continue;
            if (dict.find(diff) == dict.end())
                continue;
            if (diff < D)
                D = diff;
        }
    }

    cout << "Answer: " << D << endl;
    return 0;
}
