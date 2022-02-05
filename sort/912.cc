class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size()-1);
        return nums;
    }
private:
    void quicksort(std::vector<int>& nums, int begin, int end) {
        if (end <= begin) return;
        int first = begin, last = end;
        int pivot = nums[first];
        while (first < last) {
            while (first < last && nums[last] >= pivot)
                --last;
            nums[first] = nums[last];
            while (first < last && nums[first] <= pivot)
                ++first;
            nums[last] = nums[first];
        }
        nums[first] = pivot;
        quicksort(nums, begin, first-1);
        quicksort(nums, first+1, end);
        return;
    }
    
};
