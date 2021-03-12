class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            dp[i] = INT_MAX;
            for (const auto &coin :coins) {
                if ((i-coin) < 0) {
                    continue;
                }
                if (dp[i-coin] != INT_MAX) {
                    dp[i] = std::min(dp[i], dp[i-coin]+1);    
                }
            }
        }
        if (INT_MAX == dp[amount]) {
            return -1;
        }
        return dp[amount];
    }
};
