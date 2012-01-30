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
<<<<<<< HEAD
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                const int e = i * 10 + j;
                const int d = j * 10 + k;
                // i / k == e / d
                if ((i * d == k * e) && (e % 10) && (d % 10) && (i != j) && (j != k))
                    cout << e << "/" << d << endl;
            }
        }
    }
=======

>>>>>>> 5b646cc8448afad2267300521d085e0d013f76ee
    return 0;
}
