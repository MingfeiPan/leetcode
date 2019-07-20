func search(nums []int, target int) bool {
    if len(nums) == 0 {
        return false
    }
    var high, low, mid int
    
    high = len(nums) - 1
    for low <= high {
        //需要考虑nums[low] == nums[high]的情况 因为这个里面有dup
        for low < high && nums[low] == nums[high] {
            low++
        }
        mid = (high + low) / 2
        if target == nums[mid] {
            return true
        }        
        if nums[mid] >= nums[low] {
            //mid在高区
            if target >= nums[low] && target <= nums[mid] {
                //target在当前low跟mid之间
                high = mid - 1
            }else {
                //target在mid之上
                low = mid + 1
            }
        }else {
            //mid在低区
            if target >= nums[mid] && target <= nums[high] {
                //target在当前mid跟high之间
                low = mid + 1
            }else {
                high = mid - 1
            }
        }
    }
    return false
}
