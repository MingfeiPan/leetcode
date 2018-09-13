class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        if not nums:
            return 0
        length = len(nums)
        pre = 0
        cur = 1
        flag = False #False 1连续 True 2连续
        while cur < length:
            if nums[pre] == nums[cur]:
                if flag:
                    nums.pop(cur)
                    length -= 1
                else:
                    flag = True
                    pre += 1
                    cur += 1
            else:
                flag = False
                pre += 1
                cur += 1
                
        return len(nums)
                    
                    
                
            
        
