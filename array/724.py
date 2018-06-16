class Solution:
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        total = sum(nums)
        parta = 0
        for i in range(len(nums)):
            if (total - nums[i]) == parta:
                return i
            parta += nums[i]
            total -= nums[i]
        return -1   
            
