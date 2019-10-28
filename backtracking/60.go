func getPermutation(n int, k int) string {
    nums := make([]int, n)
    for i, _ := range nums {
        nums[i] = i+1
    }
    var factnew, index int 
    var ret []byte
    for len(nums) > 0 {
        factnew = factorial(n-1)
        n--
        index = (k-1) / factnew
        k = k - index*factnew
        ret = append(ret, byte(nums[index]+48))
        nums = append(nums[:index], nums[index+1:]...)
    }
    return string(ret)
}

func factorial(n int) int {
    ret := 1
    for n > 0 {
        ret *= n
        n--
    }
    return ret
}
