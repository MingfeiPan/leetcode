func productExceptSelf(nums []int) []int {
    ret := make([]int, len(nums))
    for i, _ := range ret {
        ret[i] = 1;
    }
    acc := 1
    for i := 1; i < len(nums); i++ {
        acc *= nums[i-1]
        ret[i] = acc
    }
    acc = 1
    for i := len(nums)-1; i > 0; i-- {
        acc *= nums[i]
        ret[i-1] *= acc
    }
    return ret
}
