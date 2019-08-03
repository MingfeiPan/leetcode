func findMin(nums []int) int {
    
    if len(nums) == 0 {
        return 0
    }
    
    var high, low, mid int
    high = len(nums) - 1
    //find the pivot, pivot will be the smallest value as well
    for low < high {
        mid = (low + high) / 2
        if nums[mid] > nums[high] {
            //异常区段
            low = mid + 1
        }else {
            high = mid
        }
    }
    return nums[low]
}
