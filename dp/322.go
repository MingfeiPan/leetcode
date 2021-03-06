func coinChange(coins []int, amount int) int {
	dp := make([]int, amount+1)
	for i, _ := range dp {
		dp[i] = math.MaxInt32
	}
	dp[0] = 0
	for i := 0; i < len(dp); i++ {
		for _, coin := range coins {
			if (i - coin) < 0 {
				continue
			}
			dp[i] = min(dp[i], 1+dp[i-coin])
		}
	}
	if dp[amount] == math.MaxInt32 {
		return -1
	}
	return dp[amount]
}

func min(n1, n2 int) int {
	if n1 < n2 {
		return n1
	} else {
		return n2
	}
}

func coinChange(coins []int, amount int) int {
    dp := make([]int, amount+1)
    dp[0] = 0
    for i := 1; i <= amount; i++ {
        dp[i] = amount+1
    }
    for i := 1; i <= amount; i++ {
        for _, coin := range coins {
            if i - coin >= 0 {
                dp[i] = min(dp[i], dp[i-coin]+1)
            }
        }
    }
    if dp[amount] > amount {
        return -1
    }
    return dp[amount]
}

func min(i int, j int) int {
    if i < j {
        return i
    }else {
        return j
    }
}
