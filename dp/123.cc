class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int min = - 100001;
        int dp[prices.size()][3][2];
        for (int i = 0; i < prices.size(); i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
            }
        }
        // check init state
        // 初始未买入
        dp[0][0][0] = 0;
        // 初始买入
        dp[0][1][1] = -prices[0];
        dp[0][2][1] = -prices[0];
        // 此状态不合法, 买入后k应该大于1
        // dp[0][0][1] = -1;
        // 此状态不合法, 起始状态k=1时应该有买入
        // dp[0][1][0] = -1;
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j < 3; j++) {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
            }
        }
        
        return dp[prices.size()-1][2][0];
    }
};
