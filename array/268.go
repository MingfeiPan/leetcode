func missingNumber(nums []int) int {
    total := len(nums) * (len(nums) + 1) / 2
    for _, v := range nums {
        total -= v
    }
    return total
}


func missingNumber(nums []int) int {
    var ret int
    for _, v := range nums {
        ret ^= v
    }
    for i := 0; i <= len(nums); i++ {
        ret ^= i
    }
    return ret
}
