class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int ret = 1;
        int dp[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
