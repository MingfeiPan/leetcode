class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>{0,0});
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = std::max(dp[0][1]+prices[1], dp[0][0]);
        dp[1][1] = std::max(dp[1][0]-prices[1], dp[0][1]);
        for (int i = 2; i < prices.size(); ++i) { 
            dp[i][0] = std::max(dp[i-1][1]+prices[i], dp[i-1][0]);
            dp[i][1] = std::max(dp[i-2][0]-prices[i], dp[i-1][1]);
        }
        return dp[prices.size()-1][0];
    }
};
