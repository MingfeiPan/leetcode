class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int diff = nums[1] - nums[0], ret = 0, cur = 0;
        for (int i = 2; i < nums.size(); ++i) {
            if ((nums[i] - nums[i-1]) == diff) {
                ++cur;
            } else {
                cur = 0;
                diff = nums[i] - nums[i-1];
            }
            ret += cur;
        }
        return ret;
    }
};
