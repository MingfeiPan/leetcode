//simple dp
int maxN(int a, int b)
{
    return a < b ? b : a;
}
int maxSubArray(int* nums, int numsSize) {
    int* ret = malloc(sizeof(int)*numsSize);
    ret[0] = nums[0];
    int max = ret[0];
    for(int i = 1; i < numsSize; i++)
    {
        ret[i] = nums[i] + (0 < ret[i-1] ? ret[i-1] : 0);
        max = maxN(max, ret[i]);
    }
    return max;
}
