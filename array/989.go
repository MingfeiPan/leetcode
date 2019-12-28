func addToArrayForm(A []int, K int) []int {
    var cur, flag, index int
    for i := len(A)-1; i >= 0; i-- {
        index++
        cur = K % 10
        K = K / 10
        if cur + A[i] + flag >= 10 {
            A[i] = cur + A[i] + flag - 10
            flag = 1
        }else {
            A[i] = cur + A[i] + flag
            flag = 0
        }
    }
    for K > 0 {
        index++
        if K % 10 + flag >= 10 {
            A = append([]int{K % 10 + flag - 10}, A...)
            flag = 1
        }else {
            A = append([]int{K % 10 + flag}, A...)
            flag = 0
        }
        K = K / 10
    }
    if len(A) == index && flag == 1{
        A = append([]int{1}, A...)
        return A
    }
    for flag == 1 {
        if A[0] + flag >= 10 {
            A[0] = A[0] + flag - 10
            A = append([]int{1}, A...)
            flag = 1
        }else {
            A[0] = A[0] + flag
            flag = 0
        }
    }
    return A
}
