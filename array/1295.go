func findNumbers(nums []int) int {
    var ret int
    for _, num := range nums {
        if checkEven(num) {
            ret++
        }
    }
    return ret
}

func checkEven(num int) bool {
    var digit int
    for num > 0 {
        digit++
        num = num / 10
    }
    if digit % 2 == 0 {
        return true
    }else {
        return false
    }
}
