func findLengthOfLCIS(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    ret := 1
    cur := 1
    for i := 1; i < len(nums); i++ {
        if nums[i] > nums[i-1] {
            cur++
        }else {
            cur = 1
        }
        if ret < cur {
            ret = cur
        }
    }
    return ret
}
