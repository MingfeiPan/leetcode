class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 1;
        int cur_count = 1;
        int total = nums.size();
        for (int i = 1; i < total; ++i) {
            if (nums[i] == nums[i-1]) {
                ++cur_count;
                if (cur_count <= 2) {
                    nums[index] = nums[i];
                    ++index;
                }
            } else {
                nums[index] = nums[i];
                ++index;
                cur_count = 1;
            }
        }
        return index;
    }
};
