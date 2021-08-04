class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> ret(2, 0);
        std::unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = m.find(target-nums[i]);
            if (iter != m.end()) {
                ret[0] = iter->second;
                ret[1] = i;
                return ret;
            }
            m[nums[i]] = i;
        }
        return ret;
    }
};
