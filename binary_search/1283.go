func smallestDivisor(nums []int, threshold int) int {
    low, high := 1, 1000000
    var mid int
    for low < high {
        mid = (low + high) / 2
        if runOnce(nums, mid) > threshold {
            low = mid+1
        }else {
            high = mid
        }
    }
    return high
}

func runOnce(nums []int, lower int) int {
    var cur int
    for _, i := range nums {
        cur += div(i, lower)
    }    
    return cur
}
func div(a int, b int) int {
    if a < b {
        return 1
    }
    if a % b == 0 {
        return a / b
    }else {
        return a / b + 1
    }
} 

func sum(nums []int) int {
    var ret int
    for _, i := range nums {
        ret += i
    }
    return ret
}
