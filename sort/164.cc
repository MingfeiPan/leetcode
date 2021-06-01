class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        std::sort(nums.begin(), nums.end());
        int ret = 0;
        for (int i = 1; i < nums.size(); ++i) {
            ret = std::max(ret, nums[i]-nums[i-1]);
        }
        return ret;
    }
};
