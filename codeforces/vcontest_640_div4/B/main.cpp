#include <iostream>
#include <vector>
using namespace std;

bool SolveOdd(int n, int k) {
    cout << "YES" << endl;
    for (int i = 1; i < k; ++i) {
        cout << 1 << " ";
    }
    cout << (n - k + 1) << endl;
    return true;
}

bool SolveEven(int n, int k) {
    cout << "YES" << endl;
    for (int i = 1; i < k; ++i) {
        cout << 2 << " ";
    }
    cout << (n - 2 * k + 2) << endl;
    return true;
}

bool Solve(int n, int k) {
    if (k > n)
        return false;

    int tmp = n - (k-1);
    if (1 == tmp % 2)
        return SolveOdd(n, k);

    if (2*k > n)
        return false;

    tmp = n - (k-1) * 2;
    if (0 == tmp % 2)
        return SolveEven(n, k);

    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;
        if (!Solve(n, k)) {
            cout << "NO" << endl;
        }
    }

    return 0;
}
