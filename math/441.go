func arrangeCoins(n int) int {
    var ret,index int
    index = 1
    for n >= 0 {
        n -= index
        index++
        ret++
    }
    return ret-1
}
