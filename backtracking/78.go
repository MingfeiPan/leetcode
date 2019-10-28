func subsets(nums []int) [][]int {
    if len(nums) == 0 {
        return [][]int{}
    }
    ret := make([][]int, 0) 
    bt(&ret, nums, []int{}, 0)
    return ret
}

func bt(ret *[][]int, nums []int, cur []int, start int) {
    *ret = append(*ret, append([]int{}, cur...))
    for i := start; i < len(nums); i++ {
        bt(ret, nums, append(cur, nums[i]), i+1)
    }
}
