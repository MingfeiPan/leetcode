class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        l = s.split(" ")
        ls = [s[::-1] for s in l]
        return " ".join(ls)
        
