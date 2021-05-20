class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = nums[0];
        for (const auto &num : nums) {
            min = std::min(min, num);
        }
        int ret = 0;
        for (const auto &num : nums) {
            ret += num - min;
        }
        return ret;
    }
};
