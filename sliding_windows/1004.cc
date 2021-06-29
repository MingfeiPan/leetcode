class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int curk = 0, left = 0, right = 0, ret = 0;
        while (right < nums.size()) {
            if (nums[right] == 0)
                ++curk;
            if (curk > k) {
                while (nums[left] == 1) {
                    ++left;
                }
                --curk;
                ++left;
            }
            ret = std::max(ret, right-left+1);
            ++right;
        }
        return ret;
    }
};
