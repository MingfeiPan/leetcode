class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        ret = ''
        flag = 0
        l1 = len(a)
        l2 = len(b)
        index1 = l1-1
        index2 = l2-1
        while index1 >= 0 and index2 >= 0:
            s = int(a[index1]) + int(b[index2]) + flag
            c = 1 if s == 1 or s == 3 else 0
            flag = 1 if s == 2 or s == 3 else 0
            ret = str(c) + ret
            index1 -= 1
            index2 -= 1
            
        
        while index1 >= 0:
            s = int(a[index1]) + flag
            c = 1 if s == 1 else 0
            flag = 1 if s == 2 else 0            
            ret = str(c) + ret
            index1 -= 1
            
        while index2 >= 0:
            s = int(b[index2]) + flag
            c = 1 if s == 1 else 0
            flag = 1 if s == 2 else 0            
            ret = str(c) + ret
            index2 -= 1            
            
        if flag == 1:
            ret = '1' + ret
            
        return ret
            
        
