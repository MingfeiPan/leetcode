
int search(int* nums, int numsSize, int target) {
    int lo = 0;
    int hi = numsSize - 1;
    int mid;
    while(lo < hi)
    {
        mid = (lo + hi) / 2;
        if(nums[hi] < nums[mid]) lo = mid + 1;
        else hi = mid;
    }
    int pivot = lo;
    lo = 0;
    hi = numsSize - 1;
    int realmid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        realmid = (mid + pivot) % numsSize;
        if(nums[realmid] == target) return realmid;
        else if(nums[realmid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
