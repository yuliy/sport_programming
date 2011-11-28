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

    map<float, string> m;
    for (int i = 0; i < N; ++i) {
        char buf[32];
        char t[8];
        scanf("%s %s", buf, t);

        float time = i * 30;
        //float time = 0.0;
        time += (t[0] - '0') * 10 * 60;
        time += (t[1] - '0') * 60;
        time += (t[3] - '0') * 10;
        time += (t[4] - '0');
        time += (t[5] - '0') * 0.1;

        m[time] = buf;
        cout << buf << ";" << time << endl;
    }

    set<string> res;
    map<float, string>::const_iterator iter = m.begin();
    for (int i = 0; i < 3; ++i, ++iter)
        res.insert(iter->second);

    cout << res.size() << endl;
    for (set<string>::const_iterator iter = res.begin(), end = res.end(); iter != end; ++iter)
        cout << *iter << endl;

    return 0;
}
