func sortedSquares(A []int) []int {
    
    var (
        index int
        ret []int
    )
    for index = 0; index < len(A) - 1;{
        if A[index] < 0 {
            index++
        }else {
            break
        }
    }
    start, end := index - 1, index
    for start >= 0 && end < len(A) {
        if abs(A[start]) <= A[end] {
            ret = append(ret, A[start] * A[start])
            start--
        }else {
            ret = append(ret, A[end] * A[end])
            end++
        }
    }
    for start >= 0 {
        ret = append(ret, A[start] * A[start])   
        start--
    }
    for end < len(A) {
        ret = append(ret, A[end] * A[end])
        end++
    }
    return ret
    
}


func abs(num int) int {
    if num < 0 {
        return -num
    }else {
        return num
    }
}
