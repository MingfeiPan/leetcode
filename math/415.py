class Solution:
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        ret = []
        l1 = len(num1) - 1
        l2 = len(num2) - 1
        flag = 0
        while l1 >= 0 and l2 >= 0:
            n1 = ord(num1[l1]) - 48
            n2 = ord(num2[l2]) - 48
            if n1 + n2 + flag > 9:
                ret.append(n1+n2+flag-10)
                flag = 1
            else:
                ret.append(n1+n2+flag)
                flag = 0
            l1 -= 1
            l2 -= 1
            
        while l1 >= 0:
            n1 = ord(num1[l1]) - 48
            if flag:
                if n1+flag > 9:
                    ret.append(n1+flag-10)
                    flag = 1
                else:
                    ret.append(n1+flag)
                    flag = 0
            else:
                ret.append(n1)
            l1 -= 1
            
        while l2 >= 0:
            n2 = ord(num2[l2]) - 48
            if flag:
                if n2+flag > 9:
                    ret.append(n2+flag-10)
                    flag = 1
                else:
                    ret.append(n2+flag)
                    flag = 0
            else:
                ret.append(n2)
            l2 -= 1   
        if flag:
            ret.append(flag)

        if len(ret) == 1:
            return str(ret[0])
        final = 0
        for i in range(len(ret)):
            final += (10 ** i) * ret[i]
        return str(final)
