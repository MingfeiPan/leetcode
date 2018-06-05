# the power set 
# P(S) = P(T) ∪ F (e, P(T))
# F (e, T) = {X ∪ {e} | X ∈ T}
# https://en.wikipedia.org/wiki/Power_set 
class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums:
            return [[]]
        key = nums[0]
        rest = self.subsets(nums[1:])
        print(rest)
        return rest + [[key]+i for i in rest]
        
            
            
        
