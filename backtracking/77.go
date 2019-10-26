func combine(n int, k int) [][]int {
    ret := make([][]int, 0)
    nums := make([]int , n)
    for i, _ := range nums {
        nums[i] = i+1
    }
    recur(&ret, 0, k, nums, []int{})
    return ret
}

func recur(ret *[][]int, start int, k int, nums []int, cur []int) {
    if k == 0 {
        // *ret = append(*ret, cur)
		// 注意这里的copy操作, 直接用cur会被引用的slice坑
        *ret = append(*ret, append([]int{}, cur...))
        return
    }else {
        for i := start; i < len(nums); i++ {
            recur(ret, i+1, k-1, nums, append(cur[:], nums[i]))
        }
    }
}

