class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int ret = INT_MIN;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cur < 0) {
                cur = nums[i];
            } else {
                cur += nums[i];
            }
            ret = cur > ret ? cur : ret;            
        }
        return ret;
    }
};
