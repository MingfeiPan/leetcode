#直接的dp全部都会tle, 需要换个方法
class Solution:
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        if n <= 0:
            return 0
        # l = [i*i for i in range(1,n) if i*i <= n]
        ret = [n]*(n+1)
        ret[0] = 0
        for i in range(0, n+1):
            # for j in [k for k in range(0,n) if k*k <= n]:
            j = 1
            while j*j + i < n + 1:
                # if i + j*j < n+1:
                ret[i + j*j] = min(ret[i + j*j], ret[i] + 1)
                j += 1
        return ret[n]
        
