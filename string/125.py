class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if s == None or s == "":
            return True
        
        s = s.lower()
        
        l = [c for c in s if c.isalnum()]
        lr = copy.copy(l)
        l.reverse()
        return lr == l
        
