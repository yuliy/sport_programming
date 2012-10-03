#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int n, v;
    scanf("%d %d", &n, &v);

    deque< pair<int, int> > boats;
    deque< pair<int, int> > cats;
    for (int i = 1; i <= n; ++i ) {
        int t, p;
        scanf("%d %d", &t, &p);
        if (t == 1)
            boats.push_back(make_pair(i, p));
        else
            cats.push_back(make_pair(i, p));
    }

    sort(boats.rbegin(), boats.rend());
    sort(cats.rbegin(), cats.rend());

    int space = 0;
    int weight = 0;
    vector<int> path;
    for (; boats.size() > 1 && cats.size() > 0 && (space+2) <= v; space += 2) {
        const int b = boats[0].second + boats[1].second;
        const int c = cats[0].second;

        weight += max(b, c);
        //cout << "(1) " << weight << endl;
        if (b > c) {
            path.push_back(boats[0].first);
            path.push_back(boats[1].first);
            boats.pop_front();
            boats.pop_front();
        } else {
            path.push_back(cats[0].first);
            cats.pop_front();
        }
    }

    for (; boats.size() && space < v; ++space) {
        const int b = boats[0].second;
        weight += b;
        //cout << "(2) " << weight << endl;
        path.push_back(boats[0].first);
        boats.pop_front();
    }

    for (; cats.size() && space < v; space += 2) {
        const int c = cats[0].second;
        weight += c;
        //cout << "(3) " << weight << endl;
        path.push_back(cats[0].first);
        cats.pop_front();
    }

    printf("%d\n", weight);
    for (vector<int>::const_iterator iter = path.begin(); iter != path.end(); ++iter)
        printf("%d ", *iter);

    return 0;
}
