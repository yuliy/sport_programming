#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <locale>
using namespace std;

typedef vector<string> TReposters;
typedef unordered_map<string, TReposters> TName2reposters;

int dfs(const string& name, const TName2reposters& name2reposters, int curDepth) {
    TName2reposters::const_iterator it = name2reposters.find(name);
    if (it == name2reposters.end())
        return curDepth;

    const TReposters& reposters = it->second;
    int res = curDepth + 1;
    for (const auto& reposter : reposters) {
        res = max(res, dfs(reposter, name2reposters, curDepth + 1));
    }
    return res;
}

void make_lower(string& s) {
    static std::locale loc;
    for (auto& ch : s) {
        ch = tolower(ch);
    }
}

int main() {

    int n;
    cin >> n;

    TName2reposters name2reposters;
    for (int i = 0; i < n; ++i) {
        string name1, name2;
        cin >> name1 >> name2 >> name2;
        make_lower(name1);
        make_lower(name2);
        name2reposters[name2].push_back(name1);
    }

    cout << dfs("polycarp", name2reposters, 1) << endl;

    return 0;
}
