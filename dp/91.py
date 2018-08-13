class Solution:
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        if s[0] == '0':
            return 0
        
        ret = list(itertools.repeat(0, len(s)+1))
        ret[0] = 1
        ret[1] = 1
        for i in range(2, len(s)+1):
            temp = int(s[i-1])
            
            if temp != 0:
                ret[i] = ret[i-1]
                
            pre = int(s[i-2])
            if pre == 1 or (pre == 2 and temp <= 6):
                ret[i] += ret[i-2]
                    
        return ret[len(s)]
                
        
