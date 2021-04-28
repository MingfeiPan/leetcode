class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> m1, m2;
        for (const auto &num : nums1) {
            auto iter = m1.find(num);
            if (iter == m1.end()) {
                m1.emplace(num, 1);
            } else {
                ++iter->second;
            }
        }
        for (const auto &num : nums2) {
            auto iter = m2.find(num);
            if (iter == m2.end()) {
                m2.emplace(num, 1);
            } else {
                ++iter->second;
            }
        }    
        std::vector<int> ret;
        for (auto iter = m1.begin(); iter != m1.end(); ++iter) {
            auto iter2 = m2.find(iter->first);
            if (iter2 == m2.end())
                continue;
            int temp = 0;
            temp = std::min(iter->second, iter2->second);
            while (temp > 0) {
                ret.emplace_back(iter->first);
                --temp;
            }
        }
        return ret;
    }
};
