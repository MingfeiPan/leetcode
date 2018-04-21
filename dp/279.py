class Solution:
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        if n <= 0:
            return 0
        l = [i*i for i in range(1,n) if i*i <= n]
        ret = [n]*(n)
        for i in range(0, n):
            for j in l:
                if i + j < n:
                    ret[i + j] = min(ret[i + j], ret[i] + 1)
            
        return ret[n-1]
