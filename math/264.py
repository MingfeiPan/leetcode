class Solution:
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 0:
            return 1
        ret = []
        ret.append(1)
        i2 = 0
        i3 = 0
        i5 = 0
        while len(ret) < n:
            n2 = ret[i2] * 2
            n3 = ret[i3] * 3
            n5 = ret[i5] * 5
            temp = min(n2, min(n3, n5))
            if temp == n2:
                i2 += 1
            if temp == n3:
                i3 += 1
            if temp == n5:
                i5 += 1
            ret.append(temp)
            
        return ret.pop()
            
        
