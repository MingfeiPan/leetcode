class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        t = [[i, j] for i in range(len(board)) for j in range(len(board[0])) if board[i][j] == 'R']
        
        total = 0
        
        i = t[0][0] + 1
        while i < len(board):
            if board[i][t[0][1]] == 'B':
                break
            if board[i][t[0][1]] == 'p':
                total += 1
                break
            i += 1
        
        i = t[0][0] - 1
        
        while i > 0:
            if board[i][t[0][1]] == 'B':
                break
            if board[i][t[0][1]] == 'p':
                total += 1
                break            
            i -= 1
            
        j = t[0][1] + 1
        
        while j < len(board[0]):
            if board[t[0][0]][j] == 'B':
                break
            if board[t[0][0]][j] == 'p':
                total += 1
                break
            j += 1
        
        j = list(t)[0][1] - 1
        
        while j > 0:
            if board[t[0][0]][j] == 'B':
                break
            if board[t[0][0]][j] == 'p':
                total += 1
                break            
            j -= 1        
        
        
        return total
