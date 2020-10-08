class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        int mid = (begin + end) / 2;
        while (begin <= end) {
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
            mid = (begin + end) / 2;
        }
        return -1;
    }
};
