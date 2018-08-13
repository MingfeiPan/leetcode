# 从固定的数变成给出的primes数组, 需要用额外数组表示indexs跟values
import itertools
class Solution:
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        if n<= 0:
            return 1
        ret = []
        ret.append(1)
        curvalue = list(itertools.repeat(0, len(primes)))
        indexs = list(itertools.repeat(0, len(primes)))
        
        while len(ret) < n:
            for i in range(len(primes)):
                curvalue[i] = ret[indexs[i]] * primes[i]
            temp = curvalue[0]
            for i in range(1, len(primes)):
                temp = min(temp, curvalue[i])
            for i in range(len(primes)):
                if temp == curvalue[i]:
                    indexs[i] += 1
            ret.append(temp)
        
        return ret.pop()
                
        
