#include <iostream>
#include <vector>
using namespace std;

int Solve(int n, int k) {
    const int m = k / (n-1);
    const int nk = m * (n-1);
    const int ch = m * n;
    int res = ch + (k - nk);
    if (k == nk) {
        --res;
    }
    return res;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;
        cout << Solve(n, k) << endl;
    }

    return 0;
}
