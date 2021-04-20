class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        std::sort(costs.begin(), costs.end());
        int ret = 0;
        for (const auto &cost : costs) {
            if (coins >= cost) {
                coins -= std::move(cost);
                ++ret;
            } else {
                break;
            }
        }
        return ret;
    }
};
