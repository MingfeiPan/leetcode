class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        ret = []
        for num in range(left, right+1):
            num = str(num)
            flag = 0
            for c in num:
                if int(c) == 0:
                    flag = 1
                elif int(num) % int(c) != 0:
                    flag = 1
            if flag == 0:
                ret.append(int(num))
            
        return ret
        
