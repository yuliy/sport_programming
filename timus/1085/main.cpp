#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

typedef vector<int> TRoute;
typedef vector< TRoute > TRoutes;

int N, M, K;

static int FindStartRoute(const TRoutes &routes, int startPoint) {
    for (int i = 0; i < M; ++i) {
        const TRoute &r = routes[i];
        if (binary_search(r.begin(), r.end(), startPoint))
            return i;
    }
    return -1;
}

const int INF = 1e9;

static void CalcPrices(vector<int> &prices, const TRoutes &routes, int money, int start, bool hasAbonement) {
    prices[start] = 0;
    const int startRoute = FindStartRoute(routes, start);
    cout << "startRoute=" << startRoute << " (start=" << start << ")" << endl;
    if (startRoute == -1)
        return;

    vector<bool> rFlags(M);
    deque<int> q;
    q.push_back(startRoute);

    int price = 0;
    while(!q.empty()) {
        if (!hasAbonement)
            price += 4;

        if ((price > money) && !hasAbonement)
            break;

        const int rnum = q.front();
        q.pop_front();

        if (rFlags[rnum])
            continue;
        rFlags[rnum] = true;

        const TRoute &route = routes[rnum];
        const int rsize = route.size();
        for (int i = 0; i < rsize; ++i) {
            const int pointNum = route[i];
            if (price < prices[pointNum])
                prices[pointNum] = price;

            for (int j = 0; j < M; ++j) {
                if (rFlags[j])
                    continue;

                if (binary_search(routes[j].begin(), routes[j].end(), pointNum))
                    q.push_back(j);
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    TRoutes routes(M);
    for (int i = 0; i < M; ++i) {
        int cnt;
        scanf("%d", &cnt);
        for (int j = 0; j < cnt; ++j) {
            int tmp;
            scanf("%d", &tmp);
            routes[i].push_back(tmp-1);
        }
        std::sort( routes[i].begin(), routes[i].end() );
    }

    scanf("%d", &K);
    vector<int> sumPrices(N);
    for (int k = 0; k < K; ++k) {
        int money, start, hasAbonement;
        scanf("%d %d %d", &money, &start, &hasAbonement);
        --start;

        vector<int> curPrices(N);
        for (int i= 0; i < N; ++i)
            curPrices[i] = INF;

        CalcPrices(curPrices, routes, money, start, hasAbonement);
        cout << "cur prices:" << endl;
        for (int i = 0; i < N; ++i)
            cout << "point " << i << " - " << sumPrices[i] << endl;

        for (int i = 0; i < N; ++i) {
            sumPrices[i] += curPrices[i];
            if (sumPrices[i] > INF)
                sumPrices[i] = INF;
        }
    }

    int min = 1e9;
    int minNum = -1;
    for (int i = 0; i < N; ++i) {
        if (sumPrices[i] < min) {
            min = sumPrices[i];
            minNum = i;
        }
    }

    cout << "sum prices:" << endl;
    for (int i = 0; i < N; ++i)
        cout << "point " << i << " - " << sumPrices[i] << endl;

    if (minNum == -1)
        printf("0\n");
    else
        printf("%d %d\n", minNum + 1, min);

    return 0;
}
