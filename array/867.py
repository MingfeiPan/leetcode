class Solution:
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        ret = [[0]*len(A) for i in range(len(A[0]))]
        for i in range(len(A)):
            for j in range(len(A[0])):
                ret[j][i] = A[i][j]
        return ret
        
