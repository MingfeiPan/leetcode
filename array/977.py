class Solution:
    def sortedSquares(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        
        ret = []
        pre, nxt = 0, len(A) - 1
        
        while pre <= nxt and nxt >= 0:
            if A[pre] ** 2 <= A[nxt] ** 2:
                ret.append(A[nxt] ** 2)
                nxt -= 1
            else:
                ret.append(A[pre] ** 2)
                pre += 1
                
        
        return list(reversed(ret))
        
