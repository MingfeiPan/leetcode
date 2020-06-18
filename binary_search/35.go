func searchInsert(nums []int, target int) int {
    if target < nums[0] {
        return 0
    }
    if target > nums[len(nums)-1] {
        return len(nums)
    }
    var mid, low, high int
    high = len(nums)-1
    for low < high {
        mid = low + (high - low) / 2
        if nums[mid] == target {
            return mid
        }else if nums[mid] < target {
            low = mid+1
        }else {
            high = mid
        }
    }
    return low
}
