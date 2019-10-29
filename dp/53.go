func maxSubArray(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    var ret, cur int
    cur = nums[0]
    ret = nums[0]
    for i := 1; i < len(nums); i++ {
        if nums[i] + cur < nums[i] {
            cur = nums[i]
        }else {
            cur = nums[i] + cur
        }
        if ret < cur {
            ret = cur
        }
    }
    return ret
}
