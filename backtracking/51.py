class Solution:
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        
        result = []
        temp = ['.'*n for i in range(0,n)]
        self.solve(result,temp,0,n)
        return result
        
    def solve(self, result, temp, row, n):
        if row == n:
            result.append(temp)
            return
        for i in range(n):
            if self.isOk(temp, row, i , n):
                t = copy.deepcopy(temp)
                t[row] = t[row][:i] + 'Q'+ t[row][i+1:]
                self.solve(result, t, row+1, n)
    
    def isOk(self, temp, row, col, n):
        for i in range(row+1):
            if temp[i][col] == 'Q':
                return False
        x = row
        y = col
        while 0 <= x and 0 <= y:
            if temp[x][y] == 'Q':
                return False
            x -= 1
            y -= 1
        
        x = row 
        y = col
        while 0 <= x and  y < n:
            if temp[x][y] == 'Q':
                return False
            x -= 1
            y += 1
        return True
    
    
