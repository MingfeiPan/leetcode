func removeElement(nums []int, val int) int {
    if len(nums) == 0 {
        return 0
    }
    var index, count int
    for index < len(nums) {
        if nums[index] != val {
            index++
            count++
        }else {
            nums = append(nums[:index], nums[index+1:]...)
        }
    }
    return count
}
