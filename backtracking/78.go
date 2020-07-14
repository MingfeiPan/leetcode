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

func subsets(nums []int) [][]int {
    if len(nums) == 0 {
        return [][]int{}
    }
    ret := make([][]int, 0)
    bfs(nums, []int{}, 0, &ret)
    return ret
}
func bfs(nums []int, cur []int, index int, ret *[][]int) {
    *ret = append(*ret, append([]int{}, cur...))
    for i := index; i < len(nums); i++ {
        bfs(nums, append(cur, nums[i]), i+1, ret)
    }
}
