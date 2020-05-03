func numJewelsInStones(J string, S string) int {
    var ret int
    m := make(map[rune]struct{})
    for _, c := range J {
        m[c] = struct{}{}
    }
    for _, c := range S {
        if _, ok := m[c]; ok {
            ret++
        }
    }
    return ret
}
