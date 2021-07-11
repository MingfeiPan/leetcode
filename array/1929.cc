class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            nums.emplace_back(nums[i]);
        }
        return nums;
    }
};
