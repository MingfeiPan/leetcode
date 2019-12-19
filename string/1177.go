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


// TLE

func canMakePaliQueries(s string, queries [][]int) []bool {
    dp := make([][]int, len(s)+1)
    ret := make([]bool, 0)
    for i, _ := range dp {
        dp[i] = make([]int, 26)
    }
    for i := 0; i < len(s); i++ {
        copy(dp[i+1], dp[i])
        // fmt.Println((s[i])-97)
        dp[i+1][s[i]-97]++
    }
    for _, query := range queries {
        var count int
        for i := 0; i < 26; i++ {
            count += (dp[query[1]+1][i] - dp[query[0]][i]) % 2
        }
        if count / 2 <= query[2] {
            ret = append(ret, true)
        }else {
            ret = append(ret, false)
        }
    }
    return ret
}
