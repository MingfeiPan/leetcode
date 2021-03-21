class Solution {
struct Item {
    int up;
    int down;
};
public:
    int wiggleMaxLength(vector<int>& nums) {
        std::vector<Item> dp;
        dp.emplace_back(Item{1,1});
        for (size_t i = 1; i < nums.size(); ++i) {
            Item cur;
            cur.up = 1;
            cur.down = 1;            
            for (size_t j = 0; j < i; ++j) {
                if (nums[i] < nums[j]) {
                    cur.down = std::max(cur.down, dp[j].up+1);
                }
                if (nums[i] > nums[j]) {
                    cur.up = std::max(cur.up, dp[j].down+1);
                }                  
            }
            dp.emplace_back(cur);
        }
        int ret = 0;
        for (auto iter = dp.begin(); iter != dp.end(); ++iter) {
            ret = std::max(ret, std::max(iter->up, iter->down));
        }
        return ret;
    }
};
