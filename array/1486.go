func xorOperation(n int, start int) int {
    var ret, index int
    for index < n {
        ret = ret ^ (index*2 + start)
        index++
    }
    return ret
}
