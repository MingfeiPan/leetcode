import "math"

func reverse(x int) int {
    var flag bool
    var ret int
    if x < 0 {
        flag = true
        x = -x
    }
    for x > 0 {
        ret = ret * 10
        ret += x % 10
        x = x / 10
    }
    
    if flag {
        ret = -ret
    }
    if ret > math.MaxInt32 {
        return 0
    }else if ret < math.MinInt32 {
        return 0
    }
    return ret
    
}
