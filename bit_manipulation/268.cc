class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int index = 1;
        int ret = 0;
        for (const auto &i : nums) {
            ret ^= i ^ index;
            ++index;
        }
        return ret;
    }
};
