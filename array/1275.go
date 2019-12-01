func tictactoe(moves [][]int) string {
    var board [3][3]int
    for i, move := range moves {
        if i % 2 == 0 {
            board[move[0]][move[1]] = 1
        }else {
            board[move[0]][move[1]] = 2
        }
    }
    ret := checkWin(board)
    if ret == 1 {
        return "A"
    }else if ret == 2 {
        return "B"
    }else {
        if len(moves) < 9 {
            return "Pending"
        }else {
            return "Draw"
        }
    }
}

func checkWin(board [3][3]int) int {
    // check row & column
    for i := 0; i < 3; i++ {
        if board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != 0 {
            return board[i][0]
        }
        if board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0 {
            return board[0][i]
        }
    }
    // check diagonal
    if board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0 {
        return board[0][0]
    }
    if board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0 {
        return board[0][2]
    }
    return 0
}
