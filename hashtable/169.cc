class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        std::unordered_map<int, int> check;
        for (const auto& num : nums) {
            auto iter = check.find(num);
            if (iter != check.end()) {
                if ((1+iter->second) > (nums.size()/2)) {
                    return iter->first;
                }
                ++iter->second;
            } else {
                ++check[num];
            }
        }
        return -1;
    }
};
