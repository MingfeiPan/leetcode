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


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1, mid = 0;
        while (start <= end) {
            mid = (start + end) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};
