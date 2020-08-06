class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int nothold, hold, temp;
        nothold = 0;
        hold = -prices[0];
        for(int i = 1; i != prices.size(); i++) {
            temp = nothold;
            nothold = max(nothold, hold+prices[i]);
            hold = max(hold, temp-prices[i]);
        }
        return nothold;
    }
};
