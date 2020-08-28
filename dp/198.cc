class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        // dp表示抢劫到这个房子位置的max
        int dp[nums.size()+1];
        for (int i = 0; i <= nums.size(); i++) {
            dp[i] = 0;
        }
        // rob house 1
        dp[1] = nums[0];
        // rob house 2
        dp[2] = nums[1];
        for (int i = 2; i <= nums.size(); i++) {
            dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
        }
        return dp[nums.size()];
    }
};
