func singleNonDuplicate(nums []int) int {
    var ret int
    for _, num := range nums {
        ret ^= num
    }
    return ret
}
