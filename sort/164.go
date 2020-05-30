import "sort"
func maximumGap(nums []int) int {
    if len(nums) < 2 {
        return 0
    }
    sort.IntSlice(nums).Sort()
    var gap int
    for i := 0; i < len(nums) - 1; i++ {
        if nums[i+1] - nums[i] > gap {
            gap = nums[i+1] - nums[i]
        }
    }
    return gap
}
