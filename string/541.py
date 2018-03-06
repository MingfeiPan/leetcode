class Solution:
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        
        l = [c for c in s]
        ret = []
        for i in range(0, len(l), 2*k):
            tmp = l[i:i+k]
            tmp.reverse()
            for a in tmp:
                ret.append(a)
            for b in l[i+k:i+2*k]:
                ret.append(b)      
        
        return "".join(ret)
        
