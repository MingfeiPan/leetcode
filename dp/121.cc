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
            // hold0 = std::max(nothold1-prices[i], hold1); 这种 case 是可以买多次的
            hold0 = std::max(-prices[i], hold1);
            hold1 = hold0;
            nothold1 = nothold0;
        }
        return nothold0;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur = INT_MAX, ret = 0;
        for (const auto& price : prices) {
            ret = std::max(ret, price - cur);
            cur = std::min(cur, price);
        }
        return ret;
    }
};
