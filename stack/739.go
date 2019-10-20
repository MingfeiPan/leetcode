func dailyTemperatures(T []int) []int {
    stack := make([]int, 0)
    // 用一个stack 记录所有index, 查看每个值左边index的大小
    for index, value := range T {
        for len(stack) > 0 && T[stack[len(stack)-1]] < value {
            T[stack[len(stack)-1]] = index - stack[len(stack)-1]
            stack = stack[:len(stack)-1]
        } 
        stack = append(stack, index)
    }
    for len(stack) > 0 {
        T[stack[len(stack)-1]] = 0
        stack = stack[:len(stack)-1]
    }
    return T
}
