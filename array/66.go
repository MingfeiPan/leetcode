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

func plusOne(digits []int) []int {
    flag := 1
    index := len(digits)-1
    for flag > 0 && index >= 0 {
        if digits[index] < 9 {
            digits[index]++
            return digits
        }else {
            digits[index] = 0
            index--
        }
    }
    return append([]int{1}, digits...)
    
}
