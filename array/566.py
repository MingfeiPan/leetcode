class Solution:
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        if not nums:
            return []
        
        col = len(nums[0])
        row = len(nums)
        
        if not row*col == r*c:
            return nums
        
        ret = [[0]*c for i in range(r)]
        temp = []
        for i in range(row):
            for j in range(col):
                temp.append(nums[i][j])
        
        for i in range(r):
            for j in range(c):
                ret[i][j] = temp.pop(0)
        return ret
                        
                    
                
        
