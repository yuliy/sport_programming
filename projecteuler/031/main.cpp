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
    int res = 0;
    for (int c200 = 0; c200 <= 1; ++c200) {
        cout << "c200=" << c200 << endl;
        for (int c100 = 0; c100 <= 2; ++c100) {
            cout << "c100=" << c100 << endl;
            for (int c50 = 0; c50 <= 4; ++c50) {
                cout << "c50=" << c50 << endl;
                for (int c20 = 0; c20 <= 10; ++c20) {
                    for (int c10 = 0; c10 <= 20; ++c10) {
                        for (int c5 = 0; c5 <= 40; ++c5) {
                            for (int c2 = 0; c2 <= 100; ++c2) {
                                for (int c1 = 0; c1 <= 200; ++c1) {
                                    const int sum = c200 * 200 +
                                                    c100 * 100 +
                                                    c50 * 50 +
                                                    c20 * 20 +
                                                    c10 * 10 +
                                                    c5 * 5 +
                                                    c2 * 2 +
                                                    c1 * 1;
                                    if (sum == 200)
                                        ++res;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "Result: " << res << endl;

    return 0;
}
