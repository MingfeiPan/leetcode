class Solution:
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        ret = []
        self.dfs(ret, [], 1, n, k)
        return ret
    
    def dfs(self, ret, temp, start, n, k):
        if k == 0:
            ret.append(temp)
            return
        for i in range(start, n+1):
            self.dfs(ret, temp + [i], i+1, n, k-1)
        
