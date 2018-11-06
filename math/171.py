class Solution:
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        ret = 0
        for i in range(len(s)):
            ret += (ord(s[i])-64)*(26 ** (len(s) - i - 1))
            
        return ret
