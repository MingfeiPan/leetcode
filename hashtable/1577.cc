class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int ret = 0;
        std::unordered_map<double, int> num_map_;
        for (size_t i = 0; i < nums1.size(); i++) {
            double val = double(nums1[i]) * double(nums1[i]);
            auto iter = num_map_.find(val);
            if (iter == num_map_.end()) {
                num_map_.emplace(std::pair(val, 1));
            }else {
                iter->second++;
            }
        }
        for (size_t i = 0; i < nums2.size()-1; i++) {
            for (size_t j = i+1; j < nums2.size(); j++) {
                auto iter = num_map_.find(double(nums2[i])*double(nums2[j]));
                if (iter != num_map_.end()) {
                    ret += iter->second;
                }
            }
        }
        num_map_.clear();
        for (size_t i = 0; i < nums2.size(); i++) {
            double val = double(nums2[i]) * double(nums2[i]);
            auto iter = num_map_.find(val);
            if (iter == num_map_.end()) {
                num_map_.emplace(std::pair(val, 1));
            }else {
                iter->second++;
            }            
        }
        for (size_t i = 0; i < nums1.size()-1; i++) {
            for (size_t j = i+1; j < nums1.size(); j++) {
                auto iter = num_map_.find(double(nums1[i])*double(nums1[j]));
                if (iter != num_map_.end()) {
                    ret += iter->second;
                }
            }
        }        
        return ret;
    }
};
