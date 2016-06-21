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
    int N;
    cin >> N;

    vector<int> n000, n001, n010, n011, n100;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        if (num == 0) {
            n000.push_back(num);
        } else if (num < 10) {
            if (n001.empty())
                n001.push_back(num);
        } else if (num < 100) {
            if (num % 10) {
                if (n011.empty())
                    n011.push_back(num);
            } else {
                if (n010.empty())
                    n010.push_back(num);
            }
        } else {
            if (n100.empty())
                n100.push_back(num);
        }
    }

    vector<int> res(n000.begin(), n000.end());
    res.insert(res.end(), n100.begin(), n100.end());
    if ((n001.size() + n010.size()) > n011.size()) {
        res.insert(res.end(), n001.begin(), n001.end());
        res.insert(res.end(), n010.begin(), n010.end());
    } else {
        res.insert(res.end(), n011.begin(), n011.end());
    }

    cout << res.size() << endl;
    for (auto elem : res) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
