class Solution:
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        l1 = len(t)
        l2 = len(s)
        
        matrix = [[0]*(l2+1) for i in range(0, l1+1)]
        for i in range(0, l1+1):
            for j in range(0, l2+1):
                if i == 0:
                    matrix[i][j] = 1
                else:
                    if j == 0:
                        matrix[i][j] = 0
                    else:
                        if t[i-1] == s[j-1]:
                            matrix[i][j] = matrix[i-1][j-1] + matrix[i][j-1]
                        else:
                            matrix[i][j] = matrix[i][j-1]
                        
        print(matrix)
        return matrix[i][j]
