class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (const auto& num : nums)
            ret ^= num;
        return ret;
    }
};
