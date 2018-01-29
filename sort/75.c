//当遇到0或2时, 把这个数放到前或者后的正确位置
void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void sortColors(int* nums, int numsSize) {
    int lo = 0;
    int hi = numsSize - 1;

    int i = 0;
    while(i < numsSize)
    {
        if(nums[i] == 0 && lo < i)
        {
            swap(&nums[i], &nums[lo]);
            lo++;
            continue;
        }
        if(nums[i] == 2 && i < hi)
        {
            swap(&nums[i], &nums[hi]);
            hi--;
            continue;
        }
        i++;
    }
}
