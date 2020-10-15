class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // reverse all then partial reverse
        if (k > nums.size()) {
            k = k % nums.size();
        }
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
        return;
    }
private:
    void reverse(std::vector<int>& nums, int start, int end) {
        int temp;
        while (start < end) {
            temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};
