class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int left = 0, right = 0, ret = 0, cur = 1;
        for (right = 0; right < nums.size(); right++) {
            cur *= nums[right];
            while (cur >= k) {
                cur /= nums[left++];
            }
            ret += right - left + 1;
        }
        return ret;
    }
};
