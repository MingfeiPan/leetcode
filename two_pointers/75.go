func sortColors(nums []int)  {
    var red, white, blue int
    blue = len(nums) - 1
    for white <= blue {
        if nums[white] == 0 {
            nums[white], nums[red] = nums[red], nums[white]
            red++
            // 此时可以移动white 因为换过来的必然是1 在white坐标之前的值 都不可能是2
            white++
        }else if nums[white] == 1 {
            white++
        }else {
            nums[white], nums[blue] = nums[blue], nums[white]
            blue--
            // 此时不可以移动white 因为换过来的还可能是2
        }
    }
}
