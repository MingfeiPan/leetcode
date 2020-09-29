class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int pivot_index = findPivot(nums);
        int begin = 0, end = nums.size() - 1;
        int mid, realmid;
        mid = (begin + end) / 2;
        
        while (begin <= end) {
            realmid = (mid+pivot_index) % nums.size();
            if (target == nums[realmid]) {
                return realmid;
            } else if (target < nums[realmid]) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
            mid = (begin+end) / 2;
        }
        return -1;
    }
private:
    int findPivot(std::vector<int>& nums) {
        int begin = 0, end = nums.size() - 1;
        int mid = (begin + end) / 2;
        while (begin < end) {
            if (nums[mid] > nums[end]) {
                begin = mid + 1;
            } else {
                end = mid;
            }
            mid = (end + begin) / 2;
        }
        return begin;
    }
};
