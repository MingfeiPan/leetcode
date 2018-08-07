class Solution:
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret = []
        nums.sort()
        used = [0]*len(nums)
        self.dfs(ret, [], nums, used)
        return ret
    
    def dfs(self, ret, temp, nums, used):
        if len(temp) == len(nums):
            ret.append(temp)
            return
        
        for i in range(0, len(nums)):
            if used[i]:
                continue
            # 因为nums可能有重复, 所以对待重复内容需要视作一块整体处理, 也就是当nums[i]与nums[i-1]相同时, 只有nums[i-1]被使用过时, 才可以使用nums[i]
            if i > 0 and nums[i] == nums[i-1] and used[i-1]:
                continue
            used[i] = 1
            self.dfs(ret, temp + [nums[i]], nums, used)
            used[i] = 0

