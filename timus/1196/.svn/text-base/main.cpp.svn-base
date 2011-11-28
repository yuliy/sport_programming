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

    set<int> dic;
    vector<int> tmp(N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &(tmp[i]));
    dic.insert(tmp.begin(), tmp.end());

    int M;
    scanf("%d", &M);

    int res = 0;
    for (int i = 0; i < M; ++i) {
        int date;
        scanf("%d", &date);
        if (dic.find(date) != dic.end())
            ++res;
    }

    cout << res << endl;

    return 0;
}
