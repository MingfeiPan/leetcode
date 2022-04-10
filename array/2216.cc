class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int ret = 0, index = 0, n = nums.size();
        bool flag = true;
        while (index < (n-1)) {
            if (flag && index % 2 == 0) {
                if (nums[index] == nums[index+1]) {
                    ++ret;
                    flag = false;
                }
            } else if (!flag && index % 2 != 0) {
                if (nums[index] == nums[index+1]) {
                    ++ret;
                    flag = true;
                }
            }
            ++index;
        }
        if ((n-ret) % 2 == 0) return ret;
        return ret+1;
    }
};
