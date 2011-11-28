#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d\n", &N);

    vector< vector<string> > a(N);
    for (int i = 0; i < N; ++i) {
        char buf[32];
        for (int j = 0; j < 3; ++j) {
            scanf("%s", buf);
            a[i].push_back(buf);
        }
    }

    vector<int> order(N);
    for (int i = 0; i < N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        --tmp;
        order[i] = tmp;
    }

    for (vector< vector<string > >::iterator iter = a.begin(), end = a.end(); iter != end; ++iter) {
        vector<string> &v = *iter;
        std::sort(v.begin(), v.end());
    }

    vector<string> res;
    string prev;
    for (vector<int>::const_iterator iter = order.begin(), end = order.end(); iter != end; ++iter) {
        const int num = *iter;
        const vector<string> &v = a[num];

        bool ok = false;
        for (vector<string>::const_iterator siter = v.begin(), send = v.end(); siter != send; ++siter) {
            if (prev < *siter) {
                res.push_back(*siter);
                ok = true;
                prev = *siter;
                break;
            }
        }

        if (!ok) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for (vector<string>::const_iterator iter = res.begin(), end = res.end(); iter != end; ++iter) {
        cout << *iter << endl;
    }

    return 0;
}
