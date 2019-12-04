func nthSuperUglyNumber(n int, primes []int) int {
    dp := make([]int, n)
    dp[0] = 1
    indexs := make([]int, len(primes))
    for i := 1; i < n; i++ {
        dp[i] = math.MaxInt32
        for j := 0; j < len(primes); j++ {
            dp[i] = min(dp[i], dp[indexs[j]]*primes[j])
        }
        for j := 0; j < len(primes); j++ {
            if dp[i] == dp[indexs[j]]*primes[j] {
                indexs[j]++
            }
        }
    }
    return dp[n-1]
}

func min(i int, j int) int {
    if i < j {
        return i
    }else {
        return j
    }
}
