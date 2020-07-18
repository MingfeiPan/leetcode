func myPow(x float64, n int) float64 {
    if n == math.MinInt32 {
        if x == 1.0 || x == -1.0 {
            return 1
        }else {
            return 0
        }
    }
    if n < 0 {
        return 1 / myPow(x, -n)
    }
    if n == 0 {
        return 1
    }
    if n % 2 == 0 {
        return myPow(x*x, n / 2)
    }
    return x*myPow(x, n-1)
}
