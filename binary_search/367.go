func isPerfectSquare(num int) bool {
    if num == 1 {
        return true
    }
    var start, end, mid int
    start = 1
    end = num
    for start <= end {
        mid = (start + end) / 2
        if mid * mid == num {
            return true
        }else if mid * mid < num {
            start = mid + 1
        }else {
            end = mid - 1
        }
    }
    return false
}

