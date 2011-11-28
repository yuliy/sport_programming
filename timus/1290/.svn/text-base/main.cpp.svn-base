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
    scanf("%d", &N);

    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        scanf("%d\n", &v[i]);

    std::sort(v.begin(), v.end(), greater<int>());
    for (vector<int>::const_iterator iter = v.begin(), end = v.end(); iter != end; ++iter)
        printf("%d\n", *iter);

    return 0;
}
