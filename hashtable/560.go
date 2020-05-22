func subarraySum(nums []int, k int) int {
    var ret, sum int
    m := make(map[int]int)
    m[0] = 1
    for i := 0; i < len(nums); i++ {
        sum += nums[i]
        if v, ok := m[sum-k]; ok {
            ret += v
        }
        if _, ok := m[sum]; ok {
            m[sum]++
        }else {
            m[sum] = 1
        }
    }
    return ret
}
