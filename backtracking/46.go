func permute(nums []int) [][]int {
    if len(nums) == 0 {
        return [][]int{}
    }
    ret := make([][]int, 0)
    bt(&ret, nums, []int{})
    return ret
}

func bt(ret *[][]int, nums []int, cur []int) {
    if len(nums) == 0 {
        // temp := append([]int{}, cur...)
        *ret = append(*ret, append([]int{}, cur...))
    }else {
        for i := 0; i < len(nums); i++ {
            temp := append([]int{}, nums[:i]...)
            tempcur := append([]int{}, cur...)
            // nums剔除当前位置元素, 递归剩下元素的permute,  cur加上当前i位置元素, go的复制操作有点日狗
            bt(ret, append(temp, nums[i+1:]...), append(tempcur, nums[i]))
        }
    }
}
