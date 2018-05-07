//最原始的算法了, 效率很低, python3 tle 只能用c能过
bool canJump(int* nums, int numsSize) {
    if(numsSize < 2)
        return 1;
    int* arr = (int*)malloc(sizeof(int)*numsSize);
    int i;
    int j;
    arr[0] = 1; 
    for(i = 1; i < numsSize; i++)
        arr[i] = 0;
    for(i = 0; i < numsSize; i++){
        if(arr[i] != 0){
            for(j = 0; j <= nums[i]; j++){
                if((i+j) < numsSize){
                    arr[i+j] = 1;
                }
            }
        }
    }
    return arr[numsSize-1];
}

