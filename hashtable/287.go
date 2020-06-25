func findDuplicate(nums []int) int {
    m := make(map[int]struct{})
    for _, num := range nums {
        if _, ok := m[num]; ok {
            return num
        }else {
            m[num] = struct{}{}
        }
    }
    return -1
}
