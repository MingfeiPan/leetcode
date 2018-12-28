class Solution:
    def validMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        size = len(A)
        if size < 3:
            return False
        
        left = 0
        while left < size-1 and A[left] < A[left+1]:
            left += 1
        right = size - 1
        while right > 0 and A[right-1] > A[right]:
            right -= 1

        return  left != size - 1 and right != 0 and right == left
                
                
            
