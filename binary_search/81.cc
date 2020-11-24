class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int pivot = findMid(nums);
        int low = 0, high = nums.size() - 1, mid = 0, realmid = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            realmid = (mid + pivot) % nums.size();
            if (nums[realmid] == target) {
                return true;
            } else if (nums[realmid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
private:
    int findMid(std::vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid = 0;
        while (low < high) {
            while (low < high && nums[low] == nums[high])
                ++low;    
            mid = (low + high) / 2;
            if (nums[mid] <= nums[high]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
