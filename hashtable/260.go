func singleNumber(nums []int) []int {
    m := make(map[int]int)
    ret := make([]int, 0)
    for _, num := range nums {
        if _, ok := m[num]; !ok {
            m[num] = 1
        }else {
            m[num]++
        }
    }
    for _, num := range nums {
        if count, ok := m[num]; ok && count == 1 {
            ret = append(ret, num)
        }
    }
    return ret
}
