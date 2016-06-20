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

enum class ECommand {
    INSERT,
    REMOVE_MIN,
    GET_MIN
};

map<int, int> m;
int sz = 0;

vector<pair<ECommand, int>> Result;

void Insert(int n) {
    ++m[n];
    ++sz;
}

void RemoveMin() {
    if (sz > 0) {
        --sz;
        const int minim = m.begin()->first;
        if (m.begin()->second > 1) {
            m.begin()->second -= 1;
        } else {
            m.erase(minim);
        }
        return;
    }

    Result.push_back(make_pair(ECommand::INSERT, 0));
}

void GetMin(int n) {
    //
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        char command[32];
        scanf("%s", command);
        if (!strcmp(command, "insert")) {
            int num;
            scanf("%d", &num);
            Insert(num);
        } else if (!strcmp(command, "removeMin")) {
            RemoveMin();
        } else if (!strcmp(command, "getMin")) {
            int num;
            scanf("%d", &num);
            GetMin(num);
        }
    }
    return 0;
}
