func checkStraightLine(coordinates [][]int) bool {
    ratex := coordinates[1][0] - coordinates[0][0]
    ratey := coordinates[1][1] - coordinates[0][1] 
    for i := 2; i < len(coordinates); i++ {
        if (coordinates[i][0] - coordinates[i-1][0]) * ratey != (coordinates[i][1] - coordinates[i-1][1]) * ratex {
            return false
        }
    }
    return true
}

