func removeDuplicates(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    cur := nums[0]
    count := 1
    flag := 1
    index := 1
    for index < len(nums) {
        if nums[index] != cur {
            cur = nums[index]
            flag = 1
            count++
            index++
        }else {
            if flag < 2 {
                flag++
                index++
                count++
            }else{
                // 依次摘除多余的 这里index不需要变化
                for index < len(nums) && nums[index] == cur {
                    nums = append(nums[:index], nums[index+1:]...)
                }
            }
        }
    }
    return count
}
