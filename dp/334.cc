class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i1 = INT_MAX, i2 = INT_MAX;
        for (auto& i : nums) {
            if (i <= i1) {
                i1 = i;
            } else if (i <= i2) {
                i2 = i;
            } else {
                return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        std::vector<int> dp(nums.size(), 0);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        for (auto& i : dp) {
            if (i == 2)
                return true;
        }
        return false;
    }
};
