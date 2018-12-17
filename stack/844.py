class Solution:
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        
        
        def solve(s):
            l = []
            for i in s:
                if i == '#':
                    try:
                        l.pop()
                    except Exception:
                        continue
                else:
                    l.append(i)
            return ''.join(l)
        
        ls = solve(S)
        lt = solve(T)
        return ls == lt
            
