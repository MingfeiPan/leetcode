class Solution:
    def isMonotonic(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        is_asc = True
        is_desc = True
        
        for i in range(1, len(A)):
            if A[i-1] < A[i]:
                is_asc = False
            if A[i-1] > A[i]:
                is_desc = False
                
        return is_asc or is_desc
        
