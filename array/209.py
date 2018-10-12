class Solution:
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        
        pre = 0
        cur = 0
        sums = 0
        ret = len(nums) + 1
        while cur < len(nums):
            sums += nums[cur]
            cur += 1
            
            while sums >= s:
                ret = min(ret, cur - pre)
                sums -= nums[pre]
                pre += 1
            
        return 0 if ret == (len(nums) + 1) else ret
