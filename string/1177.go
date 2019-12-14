// TLE
func canMakePaliQueries(s string, queries [][]int) []bool {
    ret := make([]bool, len(queries))
    for i, v := range queries {
        ret[i] = run(s[v[0]:v[1]+1], v[2])
    }
    return ret
}

func run(s string, k int) bool {
    ret := make(map[rune]int)
    for _, c := range s {
        if _, ok := ret[c]; !ok {
            ret[c] = 1
        }else {
            ret[c]++
        }
    }
    var count int
    for _, v := range ret {
        if v % 2 != 0 {
            count++
        }
    }
    for count > 1 {
        count -= 2
        k--
    }
    if k < 0 {
        return false
    }
    return true
}
