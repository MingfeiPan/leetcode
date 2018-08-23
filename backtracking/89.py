class Solution:
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        
        ret = []
        for i in range(0, 2 ** n):
            ret.append((i>>1)^i)
        return ret
        
