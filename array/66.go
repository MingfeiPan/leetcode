func plusOne(digits []int) []int {
    flag := 1
    for i := len(digits)-1; i >= 0; i-- {
        if flag == 0 {
            break
        }
        if digits[i]+flag >= 10 {
            digits[i] = digits[i] + flag - 10
            flag = 1
        }else {
            digits[i] = digits[i] + flag
            flag = 0
        }
    }
    if flag == 1 {
        digits = append([]int{1}, digits...)
    }
    return digits
}
