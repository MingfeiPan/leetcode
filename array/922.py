class Solution:
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        
        if not A:
            return A
        
        size = len(A)
        even = 0
        odd = 1
        while even < size - 1 and odd < size:
            while even < size - 1 and A[even] % 2 == 0:
                even += 2
            while odd < size and A[odd] % 2 == 1:
                odd += 2
            
            if even < size - 1 and odd < size:
                temp = A[even]
                A[even] = A[odd]
                A[odd] = temp
        
        return A
        
            
