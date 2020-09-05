class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            int temp = abs(nums[i]) - 1;
            if (nums[temp] > 0) {
                // 不影响此值 nums[temp]的下一次使用, 因为我们取了abs
                nums[temp] = -nums[temp];
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ret.push_back(i+1);
            }
        }
        return ret;
    }
};
