func findMaxLength(nums []int) int {
    var ret, count int
    m := make(map[int]int)
    m[0] = -1
    for i := 0; i < len(nums); i++ {
        if nums[i] == 0 {
            count--
        }else {
            count++
        }
        if _, ok := m[count]; ok {
            if i - m[count] > ret {
                ret = i - m[count];
            }
        } else {
            m[count] = i
        }
    }
    return ret
}


func findMaxLength(nums []int) int {
    var count, ret int
    m := make(map[int]int)
    m[0] = -1
    for i, v := range nums {
        if v == 0 {
            count--
        }else {
            count++
        }
        if index, ok := m[count]; ok {
            if i - index > ret {
                ret = i - index
            }
        }else {
            m[count] = i
        }
    }
    return ret    
}
