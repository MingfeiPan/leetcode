func canJump(nums []int) bool {
    can := make([]int, len(nums))
    for i := 1; i < len(nums); i++ {
        can[i] = -1
    }
    for i := 0; i < len(nums)-1; i++ {
        for j := 0; j <= nums[i]; j++ {
            if can[i] >= 0 && i + j < len(nums) {
                can[i+j] = 0
            }
        }
    }
    if can[len(nums)-1] == 0 {
        return true
    }else{
        return false
    }
}
