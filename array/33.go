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


func search(nums []int, target int) int {
    if len(nums) == 0 {
        return -1
    }
    
    var high, low, mid, realmid, pivot int
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
    
    pivot = low //find pivot when low == high, where nums[low-1] > nums[high]
    low, high = 0, len(nums) - 1
    
    //normal binary search with pivot high 
    for low <= high {
        mid = (low + high) / 2
        realmid = (mid + pivot) % len(nums)
        if nums[realmid] == target {
            return realmid
        }
        if nums[realmid] < target {
            low = mid + 1
        }else {
            high = mid - 1
        }
    }
    return -1
    
}
