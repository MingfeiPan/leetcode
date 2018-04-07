#itertools.combinations
class Solution:
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        if len(s)>12: return []
        def check(s):
            return 0 <= int(s) <= 255 and str(int(s)) == s
        return [s[:i] + "." + s[i:j] + "." + s[j:k] + "." + s[k:] 
                for i,j,k in itertools.combinations(range(1, len(s)),3)
                if check(s[:i]) and check(s[i:j]) and check(s[j:k]) and check(s[k:])]        
        
