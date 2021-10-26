class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int N = position.size();
        vector< pair<int, int> > pv(N);
        for (int i = 0; i < N; ++i) {
            pv[i].first = position[i];
            pv[i].second = speed[i];
        }
        sort(pv.begin(), pv.end());

        double td = -1;
        int fleetsCnt = 0;
        const double epsilon = 1e-9;
        for (auto it = pv.rbegin(); it != pv.rend(); ++it) {
            const double time = 1.0 * (target - it->first) / it->second;
            if (time > (td+epsilon)) {
                td = time;
                ++fleetsCnt;
            }
        }

        return fleetsCnt;
    }
};
