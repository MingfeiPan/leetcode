int lengthOfLIS(int* nums, int numsSize) {
    if(numsSize == 0) return 0;
    
    int arr[numsSize];
    int i;
    for(i = 0; i < numsSize; i++)
        arr[i] = 1;
    int max;
    for(i = 1; i < numsSize; i++){
        max = 1;
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i])
                max = max < arr[j] + 1 ? arr[j] + 1 : max;
        }
        arr[i] = max;
    }
    int ret = 1;
    for(i = 0; i < numsSize; i++){
        ret = ret < arr[i] ? arr[i] : ret;
    }
    
    return ret;
    
}
