int lengthOfLIS(int* nums, int numsSize) {
    if(numsSize == 0) return 0;
    
    int arr[numsSize];
    int i;
    for(i = 0; i < numsSize; i++)
        arr[i] = 1;
    for(i = 1; i < numsSize; i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i])
                arr[i] = arr[i] < arr[j] + 1 ? arr[j] + 1 : arr[i];
        }
    }
    int ret = 1;
    for(i = 0; i < numsSize; i++){
        ret = ret < arr[i] ? arr[i] : ret;
    }
    
    return ret;
    
}
