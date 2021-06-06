class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int base = nums[0], index = 0;
        for (auto &num : nums) {
            if (num == base) {
                num = index;    
            } else {
                base = num;
                ++index;
                num = index;
            }
        }
        int ret = 0;
        for (const auto &num : nums) {
            ret += num;
        }
        return ret;
    }
};
