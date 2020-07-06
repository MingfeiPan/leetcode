func hammingDistance(x int, y int) int {
    if x > y {
        x, y = y, x
    }
    binX := make([]int, 0)
    binY := make([]int, 0)
    var ret int
    for x > 0 {
        binX = append(binX, x % 2)
        x = x / 2
    }
    
    for y > 0 {
        binY = append(binY, y % 2)
        y = y / 2
    }

    reverse(binX)
    reverse(binY)
 
    var i, j int
    for i, j = 0, 0; (len(binX) - i) != (len(binY) - j); j++ {
        if binY[j] == 1 {
            ret++
        }
    }
    for i < len(binX) {
        if binX[i] != binY[j] {
            ret++
        }
        i++
        j++
    }
    return ret
}

func reverse(s []int) {
    for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
        s[i], s[j] = s[j], s[i]
    }
}
