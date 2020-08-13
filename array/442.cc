class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // try to use vector as a map
        std::vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            // as a flag
            nums[abs(nums[i])-1] *= -1;
            if (nums[abs(nums[i])-1] > 0) {
                ret.push_back(abs(nums[i]));
            }            
        }
        return ret;
    }
};
