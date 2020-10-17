class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int j = 0;
        while (j < matrix.size()) {
            if ((j+1) < matrix.size() && target > matrix[j+1][0]) {
                j++;
            } else {
                // use binary search
                if (search(matrix[j], target))
                    return true;
                j++;
            }
        }
        return false;
    }
private:
    bool search(std::vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        int mid = (start + end) / 2;
        while (start <= end) {
            if (target == nums[mid]) {
                return true;
            } else if (target > nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            mid = (start + end) / 2;
        }
        return false;
    }
};
