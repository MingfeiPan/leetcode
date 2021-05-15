class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int64_t ret = 1, i = 0, sum = 0;
        for (int64_t j = 0; j < nums.size(); ++j) {
            sum += nums[j];
            while ((j-i+1) * nums[j] > (sum + k)) {
                sum -= nums[i];
                ++i;
            }
            ret = std::max(ret, j-i+1);
        }
        return ret;
    }
};
