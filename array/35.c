/*
 * 典型binary search O(logn)
 */
int binarySearch(int* nums, int target, int start, int end)
{
    int mid = (start + end) / 2;
    if(end < start) return start;
    if(target == nums[mid]) return mid;
    else if(target < nums[mid]) return binarySearch(nums, target, start, mid - 1);
    else return binarySearch(nums, target, mid + 1, end);
    
}
int searchInsert(int* nums, int numsSize, int target) {
    return binarySearch(nums, target, 0, numsSize - 1);
}
