class Solution:
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        size = len(nums)
        arr = []
        arr.insert(0, 1)
                
        for i in range(1, size):
            maxn = 1
            for j in range(0, i):
                if nums[j] < nums[i]:
                    maxn = maxn if maxn > arr[j] + 1 else arr[j] + 1

            arr.insert(i, maxn)
            
        ret = 1
        for i in range(0, size):
            ret = ret if ret > arr[i] else arr[i]
        return ret
        
        
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        dp = [1 for _ in range(len(nums))]

        for i in range(1, len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)

        return max(dp)  
