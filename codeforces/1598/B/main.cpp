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
using TVec = vector<int>;
using TMat = vector<TVec>;

bool SolveForPairOfStudents(const TMat& v, int a, int b) {
    // p: 1 1
    // q: 1 0
    // s: 0 1
    const int N = v.size();
    int p = 0, q = 0, s = 0;
    for (int i = 0; i < N; ++i) {
        const auto& vs = v[i];
        if (vs[a] && vs[b])
            ++p;
        else if (vs[a] && !vs[b])
            ++q;
        else if (!vs[a] && vs[b])
            ++s;
    }

    if (q < N/2)
        p -= (N/2 - q);
    if (s < N/2)
        p -= (N/2 - s);

    return (p >= 0);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        TMat v(N);
        for (int i = 0; i < N; ++i) {
            TVec vs(5);
            for (int j = 0; j < 5; ++j)
                cin >> vs[j];
            v[i] = vs;
        }

        bool ok = false;
        for (int a = 0; a < 5; ++a) {
            for (int b = a+1; b < 5; ++b) {
                if (SolveForPairOfStudents(v, a, b)) {
                    ok = true;
                    break;
                }
            }
            if (ok)
                break;
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}
