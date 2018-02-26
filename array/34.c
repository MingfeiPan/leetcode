//先二分找到pivot
int binarysearch(int* nums, int target, int start, int end){
    if(start > end) return -1;
    int mid = (start + end) / 2;
    if(nums[mid] == target) return mid;
    if(nums[mid] < target) return binarysearch(nums, target, mid+1, end);
    if(nums[mid] > target) return binarysearch(nums, target, start, mid-1);
    return -1;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int index = binarysearch(nums, target, 0, numsSize-1);
    int* ret = malloc(sizeof(int)*2);
    printf("%d\n", index);
    if(index == -1){
        ret[0] = -1;
        ret[1] = -1;
        *returnSize = 2;
        return ret;
    }
    *returnSize = 2;
    int lo = index;
    int hi = index;
    while(nums[lo-1] == target && lo > 0){
        lo--;  
        // (*returnSize)++;
    }
    while(nums[hi+1] == target && hi < numsSize-1){
        hi++;
        // (*returnSize)++;
    }
    ret[0] = lo;
    ret[1] = hi;
    return ret;
    
}
