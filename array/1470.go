func shuffle(nums []int, n int) []int {
    ret := make([]int, n*2)
    var index int
    for i := 0; i < n*2; i = i+2 {
        ret[i] = nums[index]
        ret[i+1] = nums[index+n]
        index++
    }
    return ret
}
