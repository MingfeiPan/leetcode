class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 乘法跟加法不同, 从初识位置开始的每一个值都应该计入
        int ret = INT_MIN;
        int cur = 1;
        for (int i = 0; i < nums.size(); i++) {
            cur *= nums[i];
            if (cur > ret) {
                ret = cur;
            }
            if (cur == 0) {
                cur = 1;
            }
        }
        cur = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            cur *= nums[i];
            if (cur > ret) {
                ret = cur;
            }
            if (cur == 0) {
                cur = 1;
            }
        }
        return ret;
    }
};
