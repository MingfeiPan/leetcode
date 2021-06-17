class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ret = 0, lefti = -1, righti = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= left && nums[i] <= right) {
                righti = i;
            } else if (nums[i] > right) {
                lefti = i;
                righti = i;
            }
            ret += righti - lefti;
        }
        return ret;
    }
};
