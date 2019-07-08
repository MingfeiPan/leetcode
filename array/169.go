func majorityElement(nums []int) int {
    ht := make(map[int]int)
    mark := len(nums) / 2
    for _, v := range nums {
        if count, ok := ht[v]; !ok {
            ht[v] = 1
        }else {
            ht[v]++
            if count + 1 > mark {
                return v
            }
        }
    }
    
    return nums[0]
}
