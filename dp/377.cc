class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int ret = 0;
        uint64_t dp[target+1];
        for (int i = 0; i <= target; i++) {
            dp[i] = 0;
        }
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if ((i-num) >= 0) {
                    dp[i] += dp[i-num];   
                }
            }
        }
        return dp[target];
    }
};
