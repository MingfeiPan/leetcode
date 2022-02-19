class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        std::unordered_map<int, int> m;
        for (const auto& num : nums) {
            ++m[num];
        }
        int ret = 0;
        for (const auto& pair : m) {
            auto iter = m.find(pair.first+k);
            if (iter != m.end()) {
                if (k == 0) {
                    if (iter->second >= 2) {
                        ++ret;
                    }
                } else {
                    ++ret;
                }
                
            }
        }
        return ret;
    }
};
