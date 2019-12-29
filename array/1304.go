func sumZero(n int) []int {
    ret := make([]int, 0)
    baseleft, baseright := -1, 1
    if n % 2 == 1 {
        ret = append(ret, 0)
        n--
    }
    for n > 0 {
        ret = append(ret, baseleft)
        baseleft--
        ret = append(ret, baseright)
        baseright++
        n -= 2      
    }
    return ret
}
