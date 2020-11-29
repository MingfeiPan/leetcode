class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ret = 0, cur = 0;
        for (const auto& person : accounts) {
            cur = 0;
            for (const auto& money : person) {
                cur += money;
            }
            ret = max(cur, ret);
        }
        return ret;
    }
};
