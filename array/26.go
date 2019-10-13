func removeDuplicates(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    pre := nums[0]
    count := 1
    index := 1
    
    for index < len(nums) {
        if nums[index] != pre {
            pre = nums[index]
            count++
            index++
        }else{
            nums = append(nums[:index], nums[index+1:]...)
        }
    }
    return count
}
