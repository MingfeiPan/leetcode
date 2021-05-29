class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, ret = 0, count = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] == 0) {
                ++count;
            }
            while (count > 1) {
                if (nums[i] == 0)
                    --count;
                ++i;
            }
            ret = std::max(ret, j-i+1);
        }
        return ret-1;
    }
};
