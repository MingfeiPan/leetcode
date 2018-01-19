//注意负数的情况
int cmp(const void* a, const void* b)
{
    return *(int*)a < *(int*)b ? 0 : 1;
}

int maximumProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int ret0 = nums[numsSize-1]*nums[numsSize-2]*nums[numsSize-3];
    int ret1 = nums[numsSize-1]*nums[0]*nums[1];
    return ret0 < ret1 ? ret1 : ret0;
}
