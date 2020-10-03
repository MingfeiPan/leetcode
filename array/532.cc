class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ret = 0;
        std::unordered_map<int, int> m_;
        for (auto& num : nums) {
            auto iter = m_.find(num);
            if (iter != m_.end()) {
                (iter->second)++;
            } else {
                m_.emplace(num, 1);
            }
        }
        for (auto iter = m_.begin(); iter != m_.end(); ++iter) {
            auto tar_iter = m_.find(iter->first+k);
            if (tar_iter != m_.end()) {
                if (k == 0) {
                    if (tar_iter->second >= 2)
                        ret++;
                } else {
                    ret++;    
                }
            }
        }
        return ret;
    }
    
};
