func searchInsert(nums []int, target int) int {
    if target < nums[0] {
        return 0
    }
    if target > nums[len(nums)-1] {
        return len(nums)
    }
    var start, end, mid, index int
    start = 0   
    end = len(nums) - 1
    for start != end {
        mid = start + (end - start) / 2
        if target == nums[mid] {
            return mid
        }else if target > nums[mid] {
            start = mid + 1
            index = start
        }else {
            end = mid
            index = end
        }
    }
    return index
}
