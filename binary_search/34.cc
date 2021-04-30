class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 1 && nums[0] == target) {
            std::vector<int> ret = {0, 0};
            return ret;
        }
        int start = 0, end = nums.size()-1, mid = 0, cur = -1;
        std::vector<int> ret = {-1, -1};
        while (start <= end) {
            mid = (start + end) / 2;
            if (nums[mid] == target) {
                cur = mid;
                start = mid + 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;                
            }           
        }
        ret[1] = cur;

        // find right
        start = 0, end = nums.size()-1, cur = -1;
        while (start <= end) {
            mid = (start + end) / 2;
            if (nums[mid] == target) {
                cur = mid;
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;                
            }           
        }
        ret[0] = cur;
        return ret;        
    }
};
