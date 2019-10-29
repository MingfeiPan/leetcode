func longestCommonSubsequence(text1 string, text2 string) int {
    length1 := len(text1)
    length2 := len(text2)
    ret := make([][]int, length1+1)
    for i, _ := range ret {
        ret[i] = make([]int, length2+1)
    }
    for i := 0; i <= length1; i++ {
        for j := 0; j <= length2; j++ {
            if i == 0 || j == 0 {
                ret[i][j] = 0
            }else if text1[i-1] == text2[j-1] {
                ret[i][j] = ret[i-1][j-1] + 1
            }else {
                if ret[i-1][j] > ret[i][j-1] {
                    ret[i][j] = ret[i-1][j]
                }else {
                    ret[i][j] = ret[i][j-1]
                }
            }
        }
    }
    return ret[length1][length2]
}
