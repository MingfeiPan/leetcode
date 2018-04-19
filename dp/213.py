#因为首尾相连, 考虑第一位抢或不抢 两种情况分开
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
        l1 = []
        # while nums[1] > nums[0] or nums[len(nums)-1] > nums[0]:
        #     temp = nums[0]
        #     del nums[0]
        #     nums.append(temp)
        # print(nums)
        # l = [0] * len(nums)
        l.append(nums[0])
        l1.append(0)
        l.append(max(nums[0], nums[1]))
        l1.append(nums[1])
        for i in range(2, len(nums)):
            if i == len(nums) - 1:
                l.append(l[i-1])
            else:
                l.append(max(l[i-2] + nums[i], l[i-1]))
            if i == 2:
                l1.append(max(l1[i-1], nums[i]))
            else:
                l1.append(max(l1[i-2] + nums[i], l1[i-1]))

        return max(max(l), max(l1))
                
