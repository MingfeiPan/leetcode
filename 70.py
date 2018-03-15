#fibs 到n可以由n-1走一步,n-2走两步
class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        a = 1
        b = 1
        while(n > 1):
            a, b = b , a + b
            n -= 1
            
        return b
        
