class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        
        # reverse
        # nums[i:] = nums[:(i-1):-1]
        pivot = len(nums) - 2
        while pivot >= 0 and nums[pivot+1] <= nums[pivot]:
            pivot -= 1
        print(pivot)
        if pivot >= 0:
            flag = len(nums) - 1
            while flag >= 0 and nums[flag] <= nums[pivot]:
                flag -= 1
            nums[pivot], nums[flag] = nums[flag], nums[pivot]
        
            nums[(pivot+1):] = nums[:pivot:-1]
        else:
            nums.reverse()
                
        
        
