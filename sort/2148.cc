class Solution {
public:
    int countElements(vector<int>& nums) {
        // if (nums.size() <= 2) return 0;
        std::sort(nums.begin(), nums.end());
        int start = 0, end = nums.size()-1;
        while (start < (nums.size()-1) && nums[start] == nums[start+1]) ++start;
        while (end > start && nums[end] == nums[end-1]) --end;
        if (end == start) return 0;
        return end - start - 1;
    }
};
