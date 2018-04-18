#按照每一个点为终点来定义子问题
class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums)
        l = []
        # l = [0] * len(nums)
        l.append(nums[0])
        l.append(max(nums[0], nums[1]))
        for i in range(2, len(nums)):
            l.append(max(l[i-2] + nums[i], l[i-1]))
            
        return max(l)
        
