int dominantIndex(int* nums, int numsSize) {
    int first = 0;
    int second = 0;
    int findex = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(first < nums[i]){
            second = first;
            first = nums[i];
            findex = i;
        }
        else if(second < nums[i] && nums[i] < first)
        {
            second = nums[i];
        }
        else continue;
    }
    if(second*second <= first) return findex;
    else return -1;
}
