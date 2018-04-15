#还是从后向前分析, 比较s3中每一位是否能在s1或s2的当前最末位找到
class Solution:
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        l1 = len(s1)
        l2 = len(s2)
        l3 = len(s3)
        
        if l3 != l1 + l2 :
            return False
        
        matrix = [[False]*(l2+1) for i in range(0, l1+1)]
        
        for i in range(0, l1+1):
            for j in range(0, l2+1):
                if i == 0 and j == 0:
                    matrix[0][0] = True
                elif i == 0 and j != 0:
                    if matrix[i][j-1] and s2[j-1] == s3[j-1]:
                        matrix[i][j] = True
                elif i != 0 and j == 0:
                    if matrix[i-1][j] and s1[i-1] == s3[i-1]:
                        matrix[i][j] = True
                else:
                    if (matrix[i-1][j] and s1[i-1] == s3[i+j-1]) or (matrix[i][j-1] and s2[j-1] == s3[i+j-1]):
                        matrix[i][j] = True

        print(matrix)
        return matrix[i][j]        
        
                    
        
        
