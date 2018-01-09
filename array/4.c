double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    //merge two array
    if(nums1Size == 0 && nums2Size == 0) return 0.0;
    int* nums = malloc(sizeof(int)*(nums1Size + nums2Size));
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < nums1Size && j < nums2Size)
    {
        if(nums1[i] <= nums2[j]) nums[k++] = nums1[i++];
        else nums[k++] = nums2[j++];
    }
    while(i < nums1Size) nums[k++] = nums1[i++];
    while(j < nums2Size) nums[k++] = nums2[j++];
    
    int numsSize = nums1Size + nums2Size;

    if(numsSize % 2 == 1)
    {
        int temp = numsSize / 2;
        return (double)nums[temp];
    }
    else
    {
        int temp1 = numsSize / 2 - 1;
        int temp2 = numsSize  / 2;
        return (double)(((double)nums[temp1] + (double)nums[temp2]) / 2);
    }
}
