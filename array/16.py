import sys
class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        ret = sys.maxsize
        
        nums.sort()
        
        for i in range(len(nums) - 2):
            pre, nxt = i+1, len(nums) - 1
            while pre < nxt:
                s = nums[i] + nums[pre] + nums[nxt]
                if abs(s-target) < abs(ret-target):
                    ret = s
                
                if target < s:
                    nxt -= 1
                elif target > s:
                    pre += 1
                else:
                    return s
                    
        return ret
