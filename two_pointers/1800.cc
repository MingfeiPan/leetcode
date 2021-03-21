class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ret = 0;
        int cur = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                cur += nums[i];
            } else {
                ret = std::max(cur, ret);
                cur = nums[i];
            }
        }
        ret = std::max(cur, ret);
        return ret;
    }
};
