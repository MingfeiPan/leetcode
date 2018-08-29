class Solution:
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        
        for i in range(0, len(board)):
            if not board:
                return False
            for j in range(0, len(board[0])):
                if self.dfs(i, j, board, word, 0):
                    return True
        return False
                
    def dfs(self, i, j, board, word, index):
        if index == len(word):
            return True
        else:
            if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
                return False
            if word[index] == board[i][j]:
                tmp = board[i][j]
                board[i][j] = '.';
                ret = self.dfs(i-1,j,board, word, index+1) or self.dfs(i+1,j,board, word, index+1) or self.dfs(i,j-1,board, word, index+1) or self.dfs(i,j+1,board, word, index+1)
                board[i][j] = tmp;
                return ret
            else:
                return False;
