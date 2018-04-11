class Solution:
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        l1 = len(word1)
        l2 = len(word2)
        
        if l1 == 0 and l2 != 0:
            return l2
        if l1 != 0 and l2 == 0:
            return l1
        matrix = [[0]*(l2+1) for i in range(0, l1+1)]
        for i in range(0, l1+1):
            for j in range(0, l2+1):
                if i == 0:
                    matrix[i][j] = j
                elif j == 0:
                    matrix[i][j] = i
                else:
                    if word1[i-1] == word2[j-1]:
                        matrix[i][j] = matrix[i-1][j-1]
                    else:
                        matrix[i][j] = min(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]) + 1
        return matrix[l1][l2]
        
