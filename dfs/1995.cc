class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        recur(nums, 0, 0, 0);
        return ret_;
    }
private:
    int ret_ = 0;
    void recur(std::vector<int>& nums, int index, int sum, int count) {
        if (count == 3) {
            for (int i = index; i < nums.size(); ++i) {
                if (nums[i] == sum) {
                    ++ret_;
                }
            }
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            recur(nums, i+1, sum+nums[i], count+1);
        }
        return;
    }
    
};
