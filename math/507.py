class Solution:
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        
        if not num:
            return False
        
        divisors = []
        for i in range(1, num):
            if num % i == 0:
                divisors.append(i)
        return sum(divisors) == num


#better
class Solution:
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False
        ret = []
        for i in range(1, int(num ** 0.5) + 1):
            if num % i == 0 and i != num:
                ret.append(i)
                if num / i != i and num / i != num:
                    ret.append(num // i)
        
        return sum(ret) == num
        #return num == sum((i for i in range(1,  num // 2 + 1) if num % i == 0))
