/*
 * 需要多用一个k来指引新数组有效位置
 */
int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0) return 0;
    int length = numsSize;
    int temp = nums[0];
    int k = 1;
    for(int i = 1; i < numsSize; i++)
    {
        if(temp == nums[i]) length--;
        else nums[k++] = nums[i];
        temp = nums[i];
    }
    return length;
}
