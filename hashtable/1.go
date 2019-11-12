func twoSum(nums []int, target int) []int {
    m := make(map[int]int, 0)
    for i, num := range nums {
        if _, ok := m[target-num]; ok {
            return []int{m[target-num], i}
        }else {
            m[num] = i;
        }
    }
    return []int{0,1}
}
