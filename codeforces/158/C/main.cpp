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

void PrintWorkingDirectory(const vector<string> &dirs) {
    printf("/");
    for (vector<string>::const_iterator iter = dirs.begin(), end = dirs.end(); iter != end; ++iter)
        printf("%s/", iter->c_str());
    printf("\n");
}

void ChangeDirectory(const char *s, vector<string> &dirs) {
    //cout << "cd " << s << endl;
    if (*s == '/') {
        dirs.clear();
        ++s;
    }

    string dir;
    for (; *s; ++s) {
        if (*s == '/') {
            if (dir == "..")
                dirs.pop_back();
            else
                dirs.push_back(dir);
            dir = "";
        } else
            dir += *s;
    }

    if (!dir.empty()) {
        if (dir == "..")
            dirs.pop_back();
        else
            dirs.push_back(dir);
    }
}

void ProcessCommand(const char *buf, vector<string> &dirs) {
    const char *p = strchr(buf, ' ');
    if (p)
        ChangeDirectory(++p, dirs);
    else
        PrintWorkingDirectory(dirs);
}

int main() {
    int n;
    scanf("%d", &n);

    char buf[512];
    gets(buf);
    vector<string> dirs;
    for (int i = 0; i < n; ++i) {
        gets(buf);
        //cout << "LINE: " << buf << endl;
        ProcessCommand(buf, dirs);
    }

    return 0;
}
