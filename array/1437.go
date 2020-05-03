func kLengthApart(nums []int, k int) bool {
    var i, cur, flag int
    for i < len(nums) {
        if nums[i] == 0 {
            cur++
        }else {
            if flag == 0 {
                flag = 1
            } else if cur < k {
                return false
            } else {
                cur = 0
            }
        }
        i++
    }
    return true
}
