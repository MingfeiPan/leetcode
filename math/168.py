class Solution:
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        ret = ''
        while n / 26 > 1:
            temp = n % 26
            n = n // 26
            print(n)
            print(temp)
            #考虑z的情况
            if temp == 0:
                temp = 26
                n -= 1
            ret = chr(temp+64)+ret
        
        ret = chr(n+64)+ret
        return ret
