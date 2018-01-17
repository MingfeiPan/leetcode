int cmp(const void* a, const void* b)
{
    return *(int*)a < *(int*)b ? 0 : 1;
}

int arrayPairSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int result = 0;
    for(int i = numsSize - 1; i > 0; i -= 2)
    {
        result += nums[i-1];
    }
    return result;
}
