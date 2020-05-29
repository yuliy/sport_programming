#include <iostream>
#include <vector>
using namespace std;

void Solve(int num) {
    vector<int> res;
    while (num) {
        res.push_back( num % 10 );
        num /= 10;
    }
    cout << res.size() << endl;
    for (auto elem : res) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        Solve(num);
    }

    return 0;
}
