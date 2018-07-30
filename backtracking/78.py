class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums:
            return [[]]
        ret = []
        self.dfs(ret, [], nums, 0)
        return ret
    def dfs(self, ret, temp, nums, start):
        ret.append(temp)
        for i in range(start, len(nums)):
            self.dfs(ret, temp+[nums[i]], nums, i+1)
        
