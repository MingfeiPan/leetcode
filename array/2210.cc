class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int left, right, ret = 0;
        for (int i = 1; i < (nums.size()-1); ++i) {
            if (nums[i] == nums[i-1]) continue;
            left = i-1;
            right = i+1;
            while (left >= 0 && nums[left] == nums[i]) --left;
            if (left < 0) continue;
            while (right < nums.size() && nums[right] == nums[i]) ++ right;
            if (right == nums.size()) continue;
            if (nums[i] > nums[left] && nums[i] > nums[right]) ++ret;
            if (nums[i] < nums[left] && nums[i] < nums[right]) ++ret;
        }
        return ret;
    }
};
