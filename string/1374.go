func generateTheString(n int) string {
    var ret string
    if n == 1 {
        return "a"
    }
    if n % 2 == 0 {
        ret = "b"
        for n > 1 {
            ret += "a"
            n--
        }
    }else {
        ret = "bc"
        for n > 2 {
            ret += "a"
            n--
        }
    }
    return ret
}
