class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int count = 1;
        bool flag = true;
        long long ret = 0;
        ret += prices.size();
        for (int i = 1; i < prices.size();) {
            if (flag) {
                if ((prices[i] - prices[i-1]) == -1) {
                    ++count;
                    ++i;
                } else {
                    if (count >= 2)
                        ret +=  (count-1) * count / 2;
                    count = 1;
                    flag = false;
                }
            } else {
                if ((prices[i] - prices[i-1]) == -1) {
                    flag = true;
                    ++count;
                }
                ++i;
            }
        }
        ret += ((int64_t)count-1) * (int64_t)count / 2;
        return ret;
    }
};
