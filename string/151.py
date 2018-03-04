class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """

        l = s.split()
        l.reverse()
        s = " ".join(l)
        return s
        
