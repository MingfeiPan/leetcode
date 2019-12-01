func countSquares(matrix [][]int) int {
    var limit int
    if len(matrix) > len(matrix[0]) {
        limit = len(matrix[0])
    }else {
        limit = len(matrix)
    }
    var ret int
    for length := 1; length <= limit; length++ {
        for i := 0; i < len(matrix) - length+1; i++ {
            for j := 0; j < len(matrix[0]) - length+1; j++ {
                if checkSquare(matrix, i, j, length) {
                    ret++
                }
            }
        }
    }
    return ret
}

func checkSquare(matrix [][]int, rowstart int, columnstart int, length int) bool {
    for i := rowstart; i < rowstart+length; i++ {
        for j := columnstart; j < columnstart+length; j++ {
            if matrix[i][j] == 0 {
                return false
            }
        }
    }
    return true
}

