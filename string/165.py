#数组越界这里python没有php中isset这种函数 只能try catch或者临时判断index跟length的关系。。。
class Solution:
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """

        l1 = version1.split(".")
        l2 = version2.split(".")

        length = len(l2) if len(l1) < len(l2) else len(l1)
        for i in range(0, length):
            try:
                a1 = int(l1[i]) if len(l1[i]) else 0
            except IndexError:
                a1 = 0
            try:
                a2 = int(l2[i]) if len(l2[i]) else 0
            except IndexError:
                a2 = 0
            if a1 < a2:
                return -1
            if a1 > a2:
                return 1
        return 0
        
