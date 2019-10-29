func climbStairs(n int) int {
    if n == 1 {
        return 1
    }
    a := 1
    b := 2
    var temp int
    for n > 2 {
        temp = a + b
        a = b
        b = temp
        n--
    }
    return b
}
