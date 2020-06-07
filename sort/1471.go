func getStrongest(arr []int, k int) []int {
    sort.Ints(arr)
    var mid int
    length := len(arr)
    if length % 2 == 0 {
        mid = arr[len(arr)/2 - 1]
    }else {
        mid = arr[len(arr)/2]
    }
    var start, end, index int
    end = length - 1
    ret := make([]int, k)
    for k > 0 {
        if abs(arr[start], mid) > abs(arr[end], mid) {
            ret[index] = arr[start]
            start++
        }else {
            ret[index] = arr[end]
            end--
        }
        index++
        k--
    }
    return ret
}

func abs(source int, target int) int {
    if source > target {
        return source - target
    }else {
        return target - source
    }
}


