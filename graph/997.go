func findJudge(N int, trust [][]int) int {
    countArray := make([]int, N)
    judgeArray := make([]int, N)
    for _, pair := range trust {
        countArray[pair[1]-1]++
        judgeArray[pair[0]-1] = 1
    }
    for i, count := range countArray {
        if count == N - 1 && judgeArray[i] == 0 {
            return i+1
        }
    }
    return -1
}
