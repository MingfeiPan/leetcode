func printVertically(s string) []string {
    source := make([]string, 0)
    source = strings.Split(s, " ")
    var size int
    for _, s := range source {
        if len(s) > size {
            size = len(s)
        }
    }
    ret := make([]string, size)
    for i := 0; i < size; i++ {
        var temp string
        for _, s := range source {
            if i < len(s) {
                temp += string(s[i])
            }else {
                temp += string(' ')
            }
        }
        ret[i] = temp
    }
    for i := 0; i < size; i++ {
        ret[i] = strings.TrimRight(ret[i], " ")
    }
    return ret
}
