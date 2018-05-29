class Solution:
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        row = []
        column = []
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                # print(matrix[i][j])
                if matrix[i][j] == 0:
                    column.append(i)
                    row.append(j)
        
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if i in column:
                    matrix[i][j] = 0
                if j in row:
                    matrix[i][j] = 0
