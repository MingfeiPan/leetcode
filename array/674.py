class Solution:
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        ret = 1
        cur = 1
        for i in range(0, len(nums) - 1):
            if nums[i] < nums[i+1]:
                cur += 1
            else:
                cur = 1
            if cur > ret:
                ret = cur
                
        return ret
