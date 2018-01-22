//按照逆序对数量处理, i-2位置的值可能会对下一个逆序对造成影响, 所以要出现当前逆序对的值
bool checkPossibility(int* nums, int numsSize) {
    int count = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if(nums[i] < nums[i-1])
        {
            count++;
            if(1 < count) return false;
            if(i - 2 < 0 || nums[i-2] <= nums[i]) nums[i-1] = nums[i];
            else nums[i] = nums[i-1];
        }
    }
    return true;
}
