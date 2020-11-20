class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 任意 i到j的 subsum 都可以表示为 0到j的sum 减去 0到i的sum, 所以累加一遍, 如果两个差值等于k 就找到一个答案
        std::unordered_map<int, int> map_;
        map_.emplace(0, 1);
        int sum = 0;
        int ret = 0;
        for (const auto& num : nums) {
            sum += num;
            auto iter = map_.find(sum-k);
            if (iter != map_.end()) {
                ret += iter->second;
            }
            iter = map_.find(sum);
            if (iter != map_.end()) {
                ++(iter->second);
            } else {
                map_.emplace(sum, 1);
            }
        }
        return ret;
    }
};
