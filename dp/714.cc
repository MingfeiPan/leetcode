class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() == 0) {
            return 0;
        }
        int nothold, hold, temp;
        nothold = 0;
        hold = -prices[0] - fee;
        for (int i=1; i < prices.size(); i++) {
            temp = nothold;
            nothold = max(nothold, hold+prices[i]);
            hold = max(hold, temp-prices[i]-fee);
        }
        return nothold;
    }
};
