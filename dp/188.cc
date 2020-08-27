class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        if (k > prices.size()) {
            return simpleCase(prices);
        }
        std::vector<std::vector<std::vector<int>>> dp;
        for (int i = 0; i < prices.size(); i++) {
            std::vector<std::vector<int>> dp_cell;
            for (int j = 0; j <= k; j++) {
                std::vector<int> dp_item;
                dp_item.push_back(0);
                dp_item.push_back(0);
                dp_cell.push_back(dp_item);
            }
            dp.push_back(dp_cell);
        }
        // init
        for (int j = 1; j <=k; j++) {
            dp[0][j][1] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
            }
        }
        return dp[prices.size()-1][k][0];
    }
    
    int simpleCase(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int nothold = 0;
        int hold = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            nothold = max(nothold, hold+prices[i]);
            hold = max(hold, nothold-prices[i]);
        }
        return nothold;
    }
};
