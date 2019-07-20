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

func search(nums []int, target int) bool {
    if len(nums) == 0 {
        return false
    }
    
    var high, low, mid, realmid, pivot int
    high = len(nums) - 1
    //find the pivot, pivot will be the smallest value as well
    for low < high {
        
        //incase of dup
        for low < high && nums[low] == nums[high] {
            low++
        }
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
            return true
        }
        if nums[realmid] < target {
            low = mid + 1
        }else {
            high = mid - 1
        }
    }
    return false
    
}
