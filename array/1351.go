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
