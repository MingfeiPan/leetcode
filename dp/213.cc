class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(robRange(nums, 0, nums.size()-2), robRange(nums, 1, nums.size()-1));
    }
    
private:
    int robRange(vector<int>& nums, int start, int end) {
        int dp_i_1 = 0;
        int dp_i_2 = 0;
        int dp = 0;
        for (int i = start; i <= end; i++) {
            dp = max(dp_i_1+nums[i], dp_i_2);
            dp_i_1 = dp_i_2;
            dp_i_2 = dp;
        }
        return dp_i_2;
    }
};
