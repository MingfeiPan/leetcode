#O(n^2), TLE
class Solution:
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        ret = list(itertools.repeat(1, len(nums)))
        
        for i in range(len(nums)):
            for j in range(len(ret)):
                if i != j:
                    ret[j] = ret[j]*nums[i]
                
        return ret
            
# O(n)
class Solution:
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        ret = []
        temp = 1
        for i in range(0, len(nums)):
            ret.append(temp)
            temp *= nums[i]
        
        temp = 1
        for i in range(len(nums)-1, -1, -1):
            ret[i] *= temp
            temp *= nums[i]
        
        return ret
            
        
