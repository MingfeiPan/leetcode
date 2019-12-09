func primePalindrome(N int) int {
    for {
        if isPrime(N) && checkPalin(N) {
            break
        }
        N++
        if N > 10000000 && N < 100000000 {
            N = 100000000
        }
    }
    return N
}

func isPrime(n int) bool {
    if n == 1 {
        return false
    }
    for i := 2; i*i <= n; i++ {
        if n % i == 0 {
            return false
        }
    }
    return true
}

func checkPalin(n int) bool {
    if n < 0 {
        return false
    }
    var temp, ret int
    temp = n
    for temp > 0 {
        ret = temp % 10 + ret * 10
        temp = temp / 10
    }
    return ret == n
}
