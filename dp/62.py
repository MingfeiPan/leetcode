class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        matrix = [[1]*m for i in range(0,n)]
        print(matrix)
        
        for i in range(1, n):
            for j in range(1,m):
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1]
                
        return matrix[n-1][m-1]
        
        
