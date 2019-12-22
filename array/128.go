func longestConsecutive(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    // sort then check
    sort.Ints(nums)
    
    ret := 1
    cur := 1
    for i := 0; i < len(nums) - 1; i++ {
        if nums[i] == nums[i+1] {
            continue
        }else if nums[i] == nums[i+1] - 1 {
            cur++
        }else {
            cur = 1
        }
        if cur > ret {
            ret = cur
        }
    }
    return ret
    
}

func longestConsecutive(nums []int) int {
    m := make(map[int]struct{})
    for _, num := range nums {
        if _, ok := m[num]; !ok {
            m[num] = struct{}{}
        }
    }
    var ret int
    for _, num := range nums {
        // 检查当前num 是否已经在一个答案序列里了, 这一步非常tricky
        if _, ok := m[num-1]; !ok {
            temp := num
            count := 1
            for {
                if _, ok := m[temp+1]; ok {
                    temp++
                    count++
                }else {
                    break
                }
            }
            if ret < count {
                ret = count
            }            
        }
    }
    return ret
}
