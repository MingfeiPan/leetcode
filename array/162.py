class Solution:
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return None
        if len(nums) == 1:
            return 0
        for i in range(0, len(nums)):
            if i == 0:
                if nums[i] > nums[i+1]:
                    return i
            if i == len(nums) - 1:
                if nums[i] > nums[i-1]:
                    return i
            else:
                if nums[i] > nums[i-1] and nums[i] > nums[i+1]:
                    return i
                    
        
            
            
                
        
