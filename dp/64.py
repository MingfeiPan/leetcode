class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])

        matrix = [[0]*n for i in range(0, m)]
        for i in range(0, m):
            for j in range(0, n):
                if i == 0 and j == 0:
                    matrix[i][j] = grid[i][j]
                elif i == 0 and j != 0:
                    matrix[i][j] = matrix[i][j-1] + grid[i][j]
                elif i != 0 and j == 0:
                    matrix[i][j] = matrix[i-1][j] + grid[i][j]
                else:
                    matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1]) + grid[i][j]
        return matrix[i][j]
