#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    map<string, int> device2count;
    map<string, int> device2cost;

    for (int i = 0; i < 6; ++i) {
        string name;
        string device;
        int cost = 0;
        cin >> name >> device >> cost;

        device2count[device] += 1;

        const auto it = device2cost.find(device);
        if (it != device2cost.end()) {
            device2cost[device] = min(it->second, cost);
        } else {
            device2cost[device] = cost;
        }
    }

    string bestDevice;
    int bestDeviceCount = 0;
    int bestDeviceCost = 1e9;
    for (const auto& dc : device2count) {
        const string& device = dc.first;
        const int count = dc.second;
        const int cost = device2cost[device];

        if (
            (count > bestDeviceCount)
            ||
            ((count == bestDeviceCount) && (cost < bestDeviceCost))
        ) {
            bestDevice = device;
            bestDeviceCount = count;
            bestDeviceCost = cost;
        }
    }

    cout << bestDevice << endl;

    return 0;
}
