#include <iostream>
#include <vector>
using namespace std;

int Solve(int n, int k) {
    //
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
