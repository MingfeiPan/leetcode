#for loop + while loop看似两层循环, 但是while loop只会出现在n-1 is None的情况下 所以 整体时间复杂度O(n)
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)
        
        ret = 0
        
        for num in num_set:
            
            if num - 1 not in num_set:
                cur_len = 1
            
                while num + 1 in num_set:
                    cur_len += 1
                    num += 1
                
                
                ret = max(ret, cur_len)
            
        return ret
            
