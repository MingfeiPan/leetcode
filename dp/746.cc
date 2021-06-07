class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::vector<int> dp(cost.size()+1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        int i = 0;
        for (i = 2; i < cost.size(); ++i) {
            dp[i] = std::min(dp[i-1], dp[i-2]) + cost[i];
        }
        
        return std::min(dp[i-1], dp[i-2]);
    }
};
