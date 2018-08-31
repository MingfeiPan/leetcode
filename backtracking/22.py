class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n == 0:
            return []
        ret = []
        self.dfs(ret, '(', 1, 0, n)
        return ret
    
    def dfs(self, ret, temp, left, right, n):
        if len(temp) == n*2 - 1:
            if left - right == 1:
                ret.append(temp+')')
                return
        else:
            if left < right:
                return
            else:
                self.dfs(ret, temp+'(', left+1, right, n)
                self.dfs(ret, temp+')', left, right+1, n)
        
    
