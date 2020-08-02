func getWinner(arr []int, k int) int {
    var ret, count int
    ret = arr[0]
    for i := 1; i < len(arr); i++ {
        if arr[i] > ret {
            ret = arr[i]
            count = 0
        }
        count++
        if count == k {
            break
        }
        
    }
    return ret
}
