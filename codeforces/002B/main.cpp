#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector< pair<string, int> > log;
    map< string, int > name2score;
    for (int i = 0; i < n; ++i) {
        string name;
        int score;
        cin >> name >> score;

        log.push_back( make_pair(name, score) );
        name2score[name] += score;
    }

    int max = -1;
    for (map< string, int >::const_iterator iter = name2score.begin(), end = name2score.end(); iter != end; ++iter) {
        if (iter->second > max)
            max = iter->second;
    }

    set<string> winners;
    for (map< string, int >::const_iterator iter = name2score.begin(), end = name2score.end(); iter != end; ++iter) {
        if (iter->second == max)
            winners.insert(iter->first);
    }

    map< string, int > n2s;
    for (vector< pair<string, int> >::const_iterator iter = log.begin(), end = log.end(); iter != end; ++iter) {
        n2s[iter->first] += iter->second;
        const int cur = n2s[iter->first];
        if ((cur >= max) && (winners.find(iter->first) != winners.end())) {
            cout << iter->first << endl;
            break;
        }
    }

    return 0;
}
