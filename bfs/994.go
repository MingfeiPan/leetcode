type Item struct {
    x int
    y int
    epoch int
}
func orangesRotting(grid [][]int) int {
    var ret int
    queue := make([]*Item, 0)
    for i := 0; i < len(grid); i++ {
        for j := 0; j < len(grid[0]); j++ {
            if grid[i][j] == 2 {
                queue = append(queue, &Item{i, j, 0})
            }
        }
    }
    for len(queue) > 0 {
        item := queue[0]
        queue = queue[1:]
        // check neighbors
        if item.x > 0 {
            if grid[item.x-1][item.y] == 1 {
                queue = append(queue, &Item{item.x-1, item.y, item.epoch+1})
                grid[item.x-1][item.y] = 2
            }
        }
        if item.x < len(grid)-1 {
            if grid[item.x+1][item.y] == 1 {
                queue = append(queue, &Item{item.x+1, item.y, item.epoch+1})
                grid[item.x+1][item.y] = 2
            }
        }
        if item.y > 0 {
            if grid[item.x][item.y-1] == 1 {
                queue = append(queue, &Item{item.x, item.y-1, item.epoch+1})
                grid[item.x][item.y-1] = 2
            }
        }
        if item.y < len(grid[0])-1 {
            if grid[item.x][item.y+1] == 1 {
                queue = append(queue, &Item{item.x, item.y+1, item.epoch+1})
                grid[item.x][item.y+1] = 2
            }
        }
        ret = item.epoch
    }
    
    for i := 0; i < len(grid); i++ {
        for j := 0; j < len(grid[0]); j++ {
            if grid[i][j] == 1 {
                return -1
            }
        }
    }    
    return ret
}
