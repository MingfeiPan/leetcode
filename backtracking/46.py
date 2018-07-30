class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n = len(nums)
        ret = []
        def perm(nums, k):
            if k == 1:
                ret.append(copy.copy(nums))
                return
            for i in range(0,k):
                #注意n-k与n-k+i的区别 标出每次交换的位置不同
                nums[n-k], nums[n-k+i] = nums[n-k+i], nums[n-k]   
                perm(nums, k-1)
                nums[n-k], nums[n-k+i] = nums[n-k+i], nums[n-k]
            
        perm(nums, n)
        return ret
            
#dfs
class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret = []
        self.dfs(ret, [], nums)
        return ret
        
    def dfs(self, ret, temp, nums):
        if len(temp) == len(nums):
            ret.append(temp)
        for i in range(0, len(nums)):
            if nums[i] in temp:
                continue
            else:
                self.dfs(ret, temp+[nums[i]], nums)
        
            
            
             
        
