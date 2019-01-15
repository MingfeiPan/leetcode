class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        def is_good(x, target):
            return abs(target ** 2 - x) < 0.0001
                
        target = x / 2
        while not is_good(x, target):
            target = (target + x / target) / 2
        
        return int(target)
