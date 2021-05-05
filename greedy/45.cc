class Solution {
public:
    int jump(vector<int>& nums) {
        std::vector<int> dp(nums.size(), -1);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (dp[i] == -1)
                continue;
            for (int j = 0; j <= nums[i]; ++j) {
                if ((i+j) >= nums.size())
                    break;
                if (dp[i+j] == -1) {
                    dp[i+j] = dp[i] + 1;
                } else {
                    dp[i+j] = std::min(dp[i+j], dp[i] + 1);
                }
            }
        }
        for (const auto &num : dp) {
            std::cout << num << std::endl;
        }
        return dp[nums.size()-1];
    }
};
