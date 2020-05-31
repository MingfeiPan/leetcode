maxProduct(nums []int) int {
    var ret int
    for i := 0; i < len(nums); i++ {
        for j := i+1; j < len(nums); j++ {
            if (nums[i]-1)*(nums[j]-1) > ret {
                ret = (nums[i]-1)*(nums[j]-1)
            }
        }
    }
    return ret
}
