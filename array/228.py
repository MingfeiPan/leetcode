class Solution:
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if len(nums) == 1:
            return ['{}'.format(nums[0])]
        
        ret = []
        i = 0
        while i < len(nums):
            cur = nums[i]
            while i+1 < len(nums) and (nums[i+1] - nums[i]) == 1:
                i += 1
            
            if cur is not nums[i]:
                ret.append('{}->{}'.format(cur, nums[i]))
            else:
                ret.append(str(cur))
            i += 1
        return ret
        
