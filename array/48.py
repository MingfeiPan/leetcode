class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        temp = copy.deepcopy(matrix[::-1])
        a = len(matrix)
        b = len(matrix[0])
        
        for i in range(a):
            for j in range(b):
                matrix[j][i] = temp[i][j]
        # matrix = zip(*matrix[::-1])
            
            
        
