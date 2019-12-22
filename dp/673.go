func findNumberOfLIS(nums []int) int {
    if len(nums) <= 1 {
        return len(nums)
    }
    dp := make([]int, len(nums))
    countTable := make([]int, len(nums))
    dp[0] = 1
    countTable[0] = 1
    var longest int
    for i := 1; i < len(nums); i++ {
        dp[i] = 1
        countTable[i] = 1
        for j := i-1; j >= 0; j-- {
            if nums[i] > nums[j] {
                if dp[i] < dp[j] + 1 {
                    // 找到了更大的lis, 更新两张表
                    dp[i] = dp[j] + 1
                    countTable[i] = countTable[j]
                }else if dp[i] == dp[j] + 1 {
                    // 没找到更大的lis, 但是找到了相同的, 可以累加count table
                    countTable[i] += countTable[j]
                }
            }
        }
        if longest < dp[i] {
            longest = dp[i]
        }
    }
    var ret int
    for i := 0; i < len(dp); i++ {
        if dp[i] == longest {
            ret += countTable[i]
        }
    }
    
    return ret
}
