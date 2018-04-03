class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        ret = []
        nums.sort()
        
        for i in range(0, len(nums)-2):
            if i > 0 and nums[i-1] == nums[i]:
                continue
            left = i+1
            right = len(nums)-1
            while left < right:
                s = nums[i] + nums[right] + nums[left]
                if s < 0:
                    left += 1
                elif s > 0:
                    right -= 1
                else:
                    ret.append([nums[i], nums[left], nums[right]])
                    while left < right and nums[left] == nums[left+1]:
                        left += 1
                    while left < right and nums[right-1] == nums[right]:
                        right -= 1
                    
                    right -= 1
                    left += 1
        
        return ret
      
