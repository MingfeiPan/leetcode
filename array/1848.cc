class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int left = start, right = start;
        while (left >= 0 || right < nums.size()) {
            if (left >= 0 && nums[left] == target) {
                return start - left;
            }
            --left;
            if (right < nums.size() && nums[right] == target) {
                return right - start;
            }
            ++right;
        }
        return 0;
    }
};
