class Solution:
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        ret = []
        self.dfs(ret, [], 1, n, k)
        return ret
    
    def dfs(self, ret, temp, start, target, num):
        if target < 0:
            return
        if len(temp) == num and target == 0:
            ret.append(temp)
            return
        for i in range(start, 10):
            self.dfs(ret, temp+[i], i+1, target-i, num)
        
