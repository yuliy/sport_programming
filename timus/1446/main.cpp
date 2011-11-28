#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

const char SLYTHERIN[] = "Slytherin";
const char HUFFLEPUFF[] = "Hufflepuff";
const char GRYFFINDOR[] = "Gryffindor";
const char RAVENCLAW[] = "Ravenclaw";

static void PrintNames(const vector<string> &names) {
    for (vector<string>::const_iterator iter = names.begin(), end = names.end(); iter != end; ++iter)
        printf("%s\n", iter->c_str());
}

int main() {
    vector<string> vs;
    vector<string> vh;
    vector<string> vg;
    vector<string> vr;

    int N;
    scanf("%d\n", &N);
    char name[210];
    char faculty[32];
    for (int i = 0; i < N; ++i) {
        gets(name);
        gets(faculty);
        //cout << name << ";" << faculty << endl;
        if (strcmp(faculty, SLYTHERIN) == 0) {
            vs.push_back(name);
        } else if (strcmp(faculty, HUFFLEPUFF) == 0) {
            vh.push_back(name);
        } else if (strcmp(faculty, GRYFFINDOR) == 0) {
            vg.push_back(name);
        } else {
            vr.push_back(name);
        }
    }

    printf("%s:\n", SLYTHERIN);
    PrintNames(vs);

    printf("\n%s:\n", HUFFLEPUFF);
    PrintNames(vh);

    printf("\n%s:\n", GRYFFINDOR);
    PrintNames(vg);

    printf("\n%s:\n", RAVENCLAW);
    PrintNames(vr);
    return 0;
}
