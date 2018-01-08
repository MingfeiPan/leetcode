//sort the input, the find max count
int cmp(const void* a, const void* b)
{
    return *(int*)a < *(int*)b ? 0 : 1;
}
int findLHS(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int result = 0;
    int i;
    int j;
    for(i = 0; i<numsSize - 1;i++)
    {
        int count = 1;
        int temp = nums[i];
        for(j = i+1; j<numsSize;j++)
        {
            if((nums[j] - temp) <= 1) count++;
            else break;
        }
        if(result < count && nums[j-1] - temp == 1) result = count;  
    }
    return result;
    
}
