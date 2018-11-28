class Solution:
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        ss = s + s
        ss = ss[1:-1]
        return True if ss.find(s) is not -1 else False
