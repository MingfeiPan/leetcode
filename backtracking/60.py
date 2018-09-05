import math
class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        nums = [i for i in range(1,n+1)]
        ret = ''
        k -= 1
        while n > 0:
            n -= 1
            index = int(k / math.factorial(n))
            k = k % math.factorial(n)
            ret += str(nums[index])
            nums.pop(index)
        return ret
        
