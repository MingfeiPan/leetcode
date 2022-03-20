class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return n >= 1 ? nums[0] : -1;
        if (k == 1) return n == 1 ? -1 : nums[1];
        if (n == 1) return k % 2 == 0 ? nums[0] : -1;
        int max = 0, count = 0;
        count = std::min(k-1, n);
        for (int i = 0; i < count; ++i) {
            max = std::max(max, nums[i]);
        }
        if (k < n) max = std::max(max, nums[k]);
        return max;
    }
};
