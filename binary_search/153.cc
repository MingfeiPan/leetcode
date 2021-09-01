class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        int mid = (start + end) / 2;
        while (start < end) {
            if (nums[mid] > nums[end]) {
                if (nums[mid] > nums[mid+1])
                    return nums[mid+1];
                start = mid+1;
            } else {
                end = mid;
            }
            mid = (start + end) / 2;
        }
        if (start == end)
            return nums[0];
        return nums[start];
    }
};
