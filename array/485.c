int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int count = 0;
    int max = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == 1) count++;
        else count = 0;
        max = count < max ? max : count;
    }
    return max;
}
