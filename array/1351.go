func countNegatives(grid [][]int) int {
    if len(grid) == 0 {
        return 0
    }
    var ret int
    volume := len(grid[0])
    for index, _ := range grid {
        i := 0
        for i < volume {
            if grid[index][i] < 0 {
                ret += volume - i
                break
            }
            i++
        }
    }
    return ret
}

func countNegatives(grid [][]int) int {
    if len(grid) == 0 {
        return 0
    }
    var ret int
    volume := len(grid[0])
    for index, _ := range grid {
        start := 0
        end := volume
        var mid int
        for start < end {
            mid = start + (end - start) / 2
            if grid[index][mid] < 0 {
                if mid == 0 || grid[index][mid-1] >= 0{
                    ret += volume - mid
                    break
                }else {
                    end = mid
                }
            }else {
                start = mid+1
            }
        }
    }
    return ret
}
