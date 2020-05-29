#include <iostream>
#include <vector>
using namespace std;

int Solve(int n, int k) {
    cout << "===============" << endl;
    const int m = k / (n-1);
    const int nk = m * (n-1);
    const int ch = m * n;
    return ch + (k - nk);
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
