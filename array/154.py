class Solution:
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        low, high = 0, len(nums) - 1
        while low < high:
            mid = (low + high) // 2
            while low < high and nums[low] == nums[high]:
                low += 1
            mid = (low + high) // 2
            
            if nums[high] < nums[mid]:
                low = mid + 1
            else:
                high = mid
                
        return nums[low]        
