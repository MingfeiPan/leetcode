class Solution:
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        
        if not nums:
            return 0
        
        sums = sum(nums[:k])
        ret = sums
        for i in range(len(nums) - k):
            sums += nums[i+k] - nums[i]
            if sums > ret:
                ret = sums
        
        return ret / k
        
