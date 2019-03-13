import functools
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        
        if numRows == 1:
            return s
        ret = [[] for _ in range(numRows)]
        pattern = numRows*2 - 2
        for i in range(len(s)):
            if i % pattern < numRows:
                ret[i % pattern].append(s[i])
            else:
                ret[pattern - (i % pattern)].append(s[i])
            
        return functools.reduce(lambda a, b : a + b ,[''.join(c) for c in ret])
        
                
