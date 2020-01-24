func containsDuplicate(nums []int) bool {
    m := make(map[int]struct{})
    for _, i := range nums {
        if _, ok := m[i]; ok {
            return true
        }else {
            m[i] = struct{}{}
        }
    }
    return false
}
