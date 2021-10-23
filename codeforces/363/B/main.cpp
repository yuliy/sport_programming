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

using ui64 = unsigned long long;
using i64 = long long;

static void PrintState(std::string msg, int i, int h, int sum, int res, const deque<int>& q) {
    /*
    cout << "_____________________ " << msg << endl
        << "i=" << i << endl
        << "h=" << h << endl
        << "sum=" << sum << endl
        << "res=" << res << endl
        << "q.size(): " << q.size() << endl;
    */
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k, h;
    cin >> n >> k;

    deque<int> q;

    int sum = 0;
    int res = 1e9;
    for (int i = 0; i < n; ++i) {
        cin >> h;
        if (q.size() < k) {
            PrintState("(1)", i, h, sum, res, q);
            sum += h;
            q.push_back(h);
            if (q.size() == k)
                res = min(sum, res);
        } else {
            PrintState("(2)", i, h, sum, res, q);
            sum -= q.front();
            sum += h;
            res = min(sum, res);
            q.pop_front();
            q.push_back(h);
        }
        PrintState("(3)", i, h, sum, res, q);
    }

    PrintState("(4)", -1, -1, sum, res, q);
    cout << res << endl;

    return 0;
}
