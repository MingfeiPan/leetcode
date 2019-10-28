func permuteUnique(nums []int) [][]int {
    if len(nums) == 0 {
        return [][]int{}
    }
    ret := make([][]int, 0)
    sort.Ints(nums)
    bt(&ret, nums, []int{})
    return ret
}

func bt(ret *[][]int, nums []int, cur []int) {
    if len(nums) == 0 {
        *ret = append(*ret, append([]int{}, cur...))
    }else {
        for i := 0; i < len(nums); i++ {
            
            //删掉重复元素的当前迭代轮次
            if i != 0 && nums[i] == nums[i-1] {
                continue
            }
            tempnum := append([]int{}, nums[:i]...)
            tempcur := append([]int{}, cur...)
            bt(ret, append(tempnum, nums[i+1:]...), append(tempcur, nums[i]))
        }
    }
}

