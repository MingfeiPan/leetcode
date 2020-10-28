class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<string> ret;
        if (nums.empty())
            return ret;
        for (int i = 0; i < nums.size(); ++i) {
            int cur = nums[i];
            while ((i+1) < nums.size() && (nums[i+1] == (nums[i]+1)))
                ++i;
            if (cur != nums[i]) {
                ret.emplace_back(std::to_string(cur) + "->" + std::to_string(nums[i]));
            } else {
                ret.emplace_back(std::to_string(cur));
            }
        }
        return ret;
    }
};
