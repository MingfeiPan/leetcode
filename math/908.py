class Solution:
    def smallestRangeI(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        
        small = min(A) + K
        big = max(A) - K
        return 0 if small > big else big - small
        
