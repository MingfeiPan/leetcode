class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        std::vector<int> ret(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            ret[i] = nums[nums[i]];
        }
        return ret;
    }
};
