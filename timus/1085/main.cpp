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

const bool DEBUG_LOG = true;

typedef vector<int> TRoute;
typedef vector< TRoute > TRoutes;

int N, M, K;

const int INF = 1e9;

static void PrintPrices(const vector<int> &prices) {
    for (int i = 0; i < N; ++i) {
        const int p = prices[i];
        if (p == INF)
            cout << "INF" << "\t";
        else
            cout << p << "\t";
    }
    cout << endl;
}

static void CalcPrices(vector<int> &prices, const TRoutes &routes, const int money, const int start, const bool hasAbonement) {
    prices[start] = 0;
    if (DEBUG_LOG) {
        cout << "prices (1): ";
        PrintPrices(prices);
    }

    vector<bool> rFlags(M);
    deque< pair<int, int> > q;
    for (int i = 0; i < M; ++i) {
        const TRoute &r = routes[i];
        if (binary_search(r.begin(), r.end(), start)) {
            q.push_back( make_pair(i, hasAbonement ? 0 : 4) );
            if (DEBUG_LOG)
                cout << "start route = " << i << "\t(" << q.back().first << "," << q.back().second << ")" << endl;
        }
    }

    while(!q.empty()) {
        const pair<int, int> rinfo = q.front();
        q.pop_front();

        const int rnum = rinfo.first;
        if (rFlags[rnum])
            continue;
        rFlags[rnum] = true;

        const int price = rinfo.second;
        if (DEBUG_LOG)
            cout << "rnum=" << rnum << "\tprice=" << price << endl;
        const int newPrice = price + (hasAbonement ? 0 : 4);

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
                    if (hasAbonement || (newPrice <= money))
                        q.push_back( make_pair(j, newPrice) );
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
        for (int i = 0; i < N; ++i)
            curPrices[i] = INF;

        if (DEBUG_LOG)
            cout << "----------------------------------------------------------" << endl;
        CalcPrices(curPrices, routes, money, start, hasAbonement);
        if (DEBUG_LOG) {
            cout << "cur prices: ";
            PrintPrices(curPrices);
        }

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

    if (DEBUG_LOG) {
        cout << "============================================================" << endl << "sum prices: ";
        PrintPrices(sumPrices);
    }

    if (minNum == -1)
        printf("0\n");
    else
        printf("%d %d\n", minNum + 1, min);

    return 0;
}
