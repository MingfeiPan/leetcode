func majorityElement(nums []int) []int {
    ret := make([]int, 0)
    m := make(map[int]int)
    for _, num := range nums {
        if _, ok := m[num]; ok {
            m[num]++
        }else {
            m[num] = 1
        }
    }
    count := len(nums) / 3
    for k, v := range m {
        if v > count {
            ret = append(ret, k)
        }
    }
    return ret
}
