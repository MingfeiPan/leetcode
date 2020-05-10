func buildArray(target []int, n int) []string {
    ret := make([]string, 0)
    index := 0
    for i := 1; i <= n && index < len(target); i++ {
        if i == target[index] {
            ret = append(ret, "Push")
            index++
        }else {
            ret = append(ret, "Push")
            ret = append(ret, "Pop")
        }
    }
    return ret
}
