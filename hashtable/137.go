func singleNumber(nums []int) int {
    m := make(map[int]int)
    for _, num := range nums {
        if _, ok := m[num]; !ok {
            m[num] = 1
        }else {
            m[num]++
        }
    }
    for n, count := range m {
        if count == 1 {
            return n
        }
    }
    return -1
}
