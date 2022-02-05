class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        std::unordered_map<int, int> m;
        int ret = 0;
        for (const auto& num1 : nums1) {
            for (const auto& num2 : nums2) {
                ++m[num1 + num2];
            }
        }
        for (const auto& num3 : nums3) {
            for (const auto& num4 : nums4) {
                ret += m[-num3-num4];
            }
        }
        return ret;
    }
};
