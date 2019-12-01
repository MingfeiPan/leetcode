func countPrimes(n int) int {
	notPrime := make(map[int]bool, n)
    var ret int
	for i := 2; i < n; i++ {
		if !notPrime[i] {
			ret++
			for j := 2; i*j < n; j++ {
				notPrime[i*j] = true
			}
		}
	}    
    return ret
}
