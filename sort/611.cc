class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ret = 0;
        std::sort(nums.begin(), nums.end());
        for (int k = nums.size()-1; k > 0; --k) {
            int i = 0;
            int j = k - 1;
            while (i < j) {
                if ((nums[i] + nums[j]) > nums[k]) {
                    ret += j - i;
                    --j;
                } else {
                    ++i;
                }
            }
        }
        return ret;
    }
};
