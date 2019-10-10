func canJump(nums []int) bool {
    var max int 
    for i := 0; i < len(nums); i++ {
        if i > max {
            return false
        }
        if nums[i] + i > max {
            max = nums[i] + i
        }
    }
    return true
}
