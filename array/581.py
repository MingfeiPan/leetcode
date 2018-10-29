class Solution:
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        cop = copy.copy(nums)
        cop.sort()
        
        start, end = 0, len(nums) - 1
        while start < len(cop) and nums[start] == cop[start]:
            start += 1
        while end > start and nums[end] == cop[end]:
            end -= 1
            
        return end-start+1
