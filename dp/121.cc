class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int ret = 0;
        int low = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (low > prices[i]) {
                low = prices[i];
            }
            if (ret < (prices[i]-low)) {
                ret = prices[i] - low;
            }
        }
        return ret;
    }
};
