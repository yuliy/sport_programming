class Solution {
public:
    int search(vector<int>& nums, int target) {
        N = nums.size();
        BegIdx = FindBeg(nums);
        P = N - BegIdx;

        int l = 0;
        int r = N-1;
        while (l < r) {
            const int m = (l + r) / 2;
            const int nums_m = get(nums, m);
            if (nums_m == target) {
                l = m;
                break;
            }

            if (target < nums_m) {
                r = m-1;
            } else {
                l = m+1;
            }
        }

        if (get(nums, l) == target) {
            int res = l + (N-P);
            if (res >= N)
                res -= N;
            return res;
        }
        return -1;
    }

    inline int get(const vector<int>& nums, int i) const {
        return (i < P) ? nums[BegIdx + i] : nums[i - P];
    }

    int FindBeg(const vector<int>& nums) const {
        for (int i = 1; i < N; ++i) {
            if (nums[i-1] > nums[i])
                return i;
        }
        return 0;
    }
private:
    int N = -1;
    int BegIdx = -1;
    int P = -1;
};
