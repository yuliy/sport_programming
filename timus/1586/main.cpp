#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

static bool IsSimple(int num) {
    const int max = sqrt(num);
    for (int i = 2; i <= (max+1); ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

//bool IS_SIMPLE_NUM[1000];

//typedef map<int, vector<int> > TPostfix2Postfixes;
//TPostfix2Postfixes Postfix2Postfixes;
//int Postfix2Cnt[1000];

static int Get3Prefix(int num) {
    num /= 10;
    int res = (num % 10);
    num /= 10;
    res += ((num % 10) * 10);
    return res;
}

static int GetPostfix(int num) {
    int res = (num % 10);
    num /= 10;
    res += ((num % 10) * 10);
    return res;
}

static void Init() {
    /*
    for (int i = 100; i < 1000; ++i) {
        if (IsSimple(i))
            Postfix2Postfixes[GetPostfix(i)].push_back(i);
    }
    */
    /*
    for (int i = 0; i < 1000; ++i)
        POSTFIX_2_CNT[i] = 0;

    for (int i = 0; i < 1000; ++i) {
        IsSimpleNum[i] = IsSimple(i);
        if (i > 100 && IsSimpleNum[i])
            Postfix2Cnt[GetPostfix(i)];
    }
    */
}

int main() {
    Init();

    int N;
    scanf("%d\n", &N);
    
    //int a[1000];
    //for (int i = 0; i < 1000; ++i)
    //    a[i] = Postfix[i];
    vector< pair<int, int> > a;
    for (TPostfix2Postfixes::const_iterator iter = Postfix2Postfixes.begin(), end = Postfix2Postfixes.end(); iter != end; ++iter)
        a.push_back( make_pair(iter->first, iter->second.size()) );

    for (int k = 0; k < (N-2); ++k) {
        vector<int> nexta;
        for (vector<int>::const_iterator iter = a.begin(), end = a.end(); iter != end; ++iter) {
            const int postfix = iter->first;
            const int cnt = iter->second;
            const vector<int> &postfixes = 
        }
        /*
        for (int i = 0; i < 1000; ++i) {
            if (a[i] <= 0)
                continue;
            const int postfix = i;
            const int cnt = a[i];
            //const int matches = Postfix2Cnt[i];
            //const vector<int> postfixes[
        }
        */
    }

    return 0;
}
