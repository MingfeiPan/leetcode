func search(nums []int, target int) int {
    if len(nums) == 0 {
        return -1
    }
    var high, low, mid int
    
    high = len(nums) - 1
    for low <= high {
        mid = (high + low) / 2
        if target == nums[mid] {
            return mid
        }
        if nums[mid] >= nums[low] {
            //mid在高区
            if target >= nums[low] && target <= nums[mid] {
                //target在当前low跟mid之前
                high = mid - 1
            }else {
                //target在mid之上
                low = mid + 1
            }
        }else {
            //mid在低区
            if target >= nums[mid] && target <= nums[high] {
                low = mid + 1
            }else {
                high = mid - 1
            }
        }
    }
    return -1
}
