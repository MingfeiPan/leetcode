class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        std::vector<int> leftmax(nums.size(), 0);
        std::vector<int> rightmin(nums.size(), 0);
        int max = 0;
        for (int i = 0; i < nums.size(); ++i) {
            max = std::max(max, nums[i]);
            leftmax[i] = max;
        }
        int min = nums[nums.size()-1];
        for (int i = (nums.size()-1); i >= 0; --i) {
            min = std::min(min, nums[i]);
            rightmin[i] = min;
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (leftmax[i-1] <= rightmin[i])
                return i;
        }
        return -1;
    }
};
