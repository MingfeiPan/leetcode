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
            
            
        
