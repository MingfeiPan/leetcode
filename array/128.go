func longestConsecutive(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    // sort then check
    sort.Ints(nums)
    
    ret := 1
    cur := 1
    for i := 0; i < len(nums) - 1; i++ {
        if nums[i] == nums[i+1] {
            continue
        }else if nums[i] == nums[i+1] - 1 {
            cur++
        }else {
            cur = 1
        }
        if cur > ret {
            ret = cur
        }
    }
    return ret
    
}
