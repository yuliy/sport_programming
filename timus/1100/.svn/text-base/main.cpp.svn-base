#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

struct comparator {
    bool operator() (const pair<int, int> &lhs, const pair<int, int> &rhs) const {
        //if (lhs.second == rhs.second)
        //    return lhs.first < rhs.second;
        return lhs.second > rhs.second;
    }
};

typedef vector< pair<int, int> > TVector;
typedef TVector::const_iterator TIterator;
static inline void yulik_sort(TVector &v) {
    const size_t cnt = v.size();
    for (size_t j = cnt-1; j >= 1; --j) {
        //cout << "j=" << j << endl;
        for (size_t i = 0; i < j; ++i) {
            //cout << "i=" << i << endl;
            if (v[i].second < v[i+1].second)
                swap(v[i], v[i+1]);
        }
    }
}

int main() {
    int N = 0;
    scanf("%d", &N);

    vector< pair<int, int> > v;
    for (int i = 0; i < N; ++i) {
        int id, m;
        scanf("%d %d", &id, &m);
        v.push_back( make_pair(id, m) );
    }

    //yulik_sort(v);
    stable_sort(v.begin(), v.end(), comparator());
    for (vector< pair<int, int> >::const_iterator iter = v.begin(), end = v.end(); iter != end; ++iter)
        printf("%d %d\n", iter->first, iter->second);

    return 0;
}
