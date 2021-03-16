class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int hold0 = 0;
        int nothold0 = 0;
        int hold1 = -prices[0];
        int nothold1 = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            nothold0 = std::max(hold1+prices[i], nothold1);
            hold0 = std::max(nothold1-prices[i], hold1);
            hold1 = hold0;
            nothold1 = nothold0;
        }
        return nothold0;   
    }
};
