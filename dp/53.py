class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        ret = -sys.maxsize
        cur = 0 
        for i in nums:
            cur = cur + i if cur > 0 else i
            ret = ret if ret > cur else cur
        return ret
