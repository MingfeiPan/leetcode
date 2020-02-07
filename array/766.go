func isToeplitzMatrix(matrix [][]int) bool {
    for i := 0; i < len(matrix); i++ {
        for j := 0; j < len(matrix[0]); j++ {
            if i != 0 && j != 0 && matrix[i-1][j-1] != matrix[i][j] {
                return false
            }
        }
    }
    return true
}
