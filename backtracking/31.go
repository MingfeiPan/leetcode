func nextPermutation(nums []int)  {
    var pre, cur int
    var flag bool
    pre = len(nums)-2
    
    // 先向前找到一个比较小的, 再向后找到一个只大一点的
    for pre >= 0 && nums[pre] >= nums[pre+1] {
        pre--
    }
    if pre >= 0 {
        flag = true
        cur = len(nums) - 1
        for cur >= pre && nums[cur] <= nums[pre] {
            cur--
        }
    }
    if flag {
        //为了达到最小, 还要reverse pre后面的元素, 因为pre后面的元素本身是降序的, 要变成升序才能是下一个最大的, 在pre+1位置开始reverse
        nums[pre], nums[cur] = nums[cur], nums[pre]
        for i, j := pre+1, len(nums)-1; i < j; i, j = i+1, j-1 {
            nums[i], nums[j] = nums[j], nums[i]
        }
    }else {
        for i, j := 0, len(nums)-1; i < j; i, j = i+1, j-1 {
            nums[i], nums[j] = nums[j], nums[i]
        }
    }
}
