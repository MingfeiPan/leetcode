func lengthOfLIS(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    ret := make([]int, len(nums))
    for i := 0; i < len(nums); i++ {
        ret[i] = 1
        for j := 0; j < i; j++ {
            if nums[i] > nums[j] {
                if ret[j] + 1 > ret[i] {
                    ret[i] = ret[j] + 1
                }
            }
        }
    }
    for i := 1; i < len(ret); i++ {
        if ret[0] < ret[i] {
            ret[0] = ret[i]
        }
    }
    return ret[0]
}

func lengthOfLIS(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    
    dp := make([]int, len(nums))
    dp[0] = 1
    ret := 1
    for i := 1; i < len(nums); i++ {
        dp[i] = 1 
        for j := i-1; j >= 0; j-- {
            if nums[i] > nums[j] {
                if dp[i] < dp[j] + 1 {
                    dp[i] = dp[j] + 1
                }
            }
        }
        if ret < dp[i] {
            ret = dp[i]
        }
    }
    return ret
}
