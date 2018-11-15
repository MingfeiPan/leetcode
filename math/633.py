import math
class Solution:
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        pre, nxt = 0, int(math.sqrt(c))
        while pre <= nxt:
            sums = pre ** 2 + nxt ** 2
            if sums < c:
                pre += 1
            elif sums > c:
                nxt -= 1
            else:
                return True
            
        return False
