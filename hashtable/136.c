/*
 * tricky的方法, 两个相同的数座xor(^操作)是0, 而0^任何数都等于任何数
 */

int singleNumber(int* nums, int numsSize) {
    int result = nums[0];
    for(int i = 1; i < numsSize; i++)
    {
        result ^= nums[i];
    }
    return result;
}
