class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = getSum(cardPoints);
        int windowSize = cardPoints.size() - k;
        int count = windowSize, cur = 0, index = 0, ret = 0;
        while (count > 0) {
            cur += cardPoints[index];
            ++index;
            --count;
        }
        ret = cur;
        for (int i = 0; i < cardPoints.size() - windowSize; ++i) {
            cur += cardPoints[windowSize+i] - cardPoints[i];
            ret = std::min(cur, ret);
        }
        return sum - ret;
    }
private:
    int getSum(std::vector<int>& nums) {
        int ret = 0;
        for (const auto &num : nums) {
            ret += num;
        }
        return ret;
    }
};
