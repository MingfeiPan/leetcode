class Solution:
    def fairCandySwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        diff = sum(A) - sum(B)
        
        A, B = set(A), set(B)
        for i in A:
            # if i > 0 and A[i] == pre:
            #     continue
            # pre = i
            temp = i - diff // 2
            if temp in B:
                return [i, temp]
        
        
