#这个题面试时遇到过, 本身matrix是有特点的, 如果从左下角开始搜索 就可以看到规律
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        i = len(matrix) - 1
        j = 0
        flag = 0
        if not matrix or not matrix[0]:
            return False
        while i >= 0 and j < len(matrix[0]):
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] < target:
                j += 1
            else:
                i -= 1
        return False
            
