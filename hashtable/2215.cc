class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::set<int> s1, s2;
        for (const auto& num : nums1) {
            s1.emplace(num);
        }
        for (const auto& num : nums2) {
            s2.emplace(num);
        }
        std::vector<std::vector<int>> ret;
        std::unordered_set<int> ret1;
        for (const auto& num : nums1) {
            if (s2.count(num) == 0) ret1.emplace(std::move(num));
        }
        ret.emplace_back(std::vector(ret1.begin(), ret1.end()));
        std::unordered_set<int> ret2;
        for (const auto& num : nums2) {
            if (s1.count(num) == 0) ret2.emplace(std::move(num));
        }
        ret.emplace_back(std::vector(ret2.begin(), ret2.end()));    
        return ret;
    }
};
