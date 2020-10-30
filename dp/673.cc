class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return 1;
        int dp[nums.size()];
        int count[nums.size()];
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            count[i] = 1;
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    if (dp[i] < (dp[j]+1)) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if (dp[i] == (dp[j]+1)) {
                        count[i] += count[j];
                    }
                }
            }
            if (dp[i] > ret) {
                ret = dp[i];
            }
        }
        int total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (dp[i] == ret) {
                total += count[i];
            }
        }
        return total;
    }
};
