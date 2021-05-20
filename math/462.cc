class Solution {
public:
    int minMoves2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int medium = 0;
        int length = nums.size();
        if (length % 2 == 1) {
            medium = nums[length/2];
        } else {
            medium = (nums[length/2] + nums[length/2-1]) / 2;
        }
        int ret = 0;
        for (const auto &num : nums) {
            ret += std::abs(num - medium);
        }
        return ret;
    }
};
