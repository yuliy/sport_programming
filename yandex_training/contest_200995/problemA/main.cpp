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

void PrintVec(const vector<int> &v) {
    cout << v.size() << " ";
    for (vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> s1;
    vector<int> s2;
    vector<int> s3;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        if (tmp < 0) {
            s1.push_back(tmp);
        } else if (tmp > 0) {
            s2.push_back(tmp);
        } else {
            s3.push_back(tmp);
        }
    }

    if (s2.empty()) {
        s2.push_back(s1.back());
        s1.pop_back();

        s2.push_back(s1.back());
        s1.pop_back();
    }

    if (s1.size() % 2 == 0) {
        s3.push_back(s1.back());
        s1.pop_back();
    }

    PrintVec(s1);
    PrintVec(s2);
    PrintVec(s3);

    return 0;
}
