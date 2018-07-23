class Solution:
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret = []
        nums.sort()
        self.dfs(ret, nums, 0, [])
        return ret
    
    def dfs(self, ret, nums, start, temp):
        ret.append(temp)
        for i in range(start, len(nums)):
            if i > start and nums[i] == nums[i-1]:
                continue
            self.dfs(ret, nums, i + 1, temp + [nums[i]])
        
        
        
