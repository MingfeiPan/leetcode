class Solution:
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        if not A:
            return A
        length = len(A)
        pre = 0
        nxt = length - 1
        while pre < nxt:
            while pre < length and A[pre] % 2 == 0:
                pre += 1
            while nxt > 0 and A[nxt] % 2 == 1:
                nxt -= 1
            if pre == length or pre >= nxt:
                break
            A[pre], A[nxt] = A[nxt], A[pre]
            pre += 1
            nxt -= 1
        return A
