class Solution:
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if not nums or len(nums) <= 1:
            return 0
        
        ret = 0
        nums.sort()
        i = 0
        while i < len(nums) - 1:
            pre = i
            nxt = i+1
            while nxt < len(nums) and nums[nxt] - nums[pre] <= k:
                if nums[nxt] - nums[pre] == k:
                    ret += 1
                    while i < len(nums)-1 and nums[i] == nums[i+1]:
                        i += 1
                    break
                else:
                    nxt += 1
            i += 1
        
        return ret
                        
        
        
